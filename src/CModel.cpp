#include <algorithm>
#include "../include/CModel.h"
#include "../include/CProgramConstants.h"
#include "../include/CVectorHelper.h"
#include "../include/CCommonInputData.h"

CModel::CModel() : CModel(2, 2)
{
	
}


CModel::CModel(int runwayCount, int specialPlaceCount)
{
	InitRunways(runwayCount);
	InitSpecialPlaces(specialPlaceCount);


}

void CModel::InitRunways(int runwayCount)
{
	for (auto i = CProgramConstants::ms_StartIdValue; i < runwayCount + CProgramConstants::ms_StartIdValue; i++)
	{
		auto runway = std::shared_ptr<CRunway>(new CRunway(std::to_string(i)));
		m_Runways.push_back(runway);
	}
}

void CModel::InitSpecialPlaces(int specPlatformCount)
{
	for (auto i = CProgramConstants::ms_StartIdValue; i < specPlatformCount + CProgramConstants::ms_StartIdValue; i++)
	{
		auto specialPlace = std::shared_ptr<CSpecialPlace>(new CSpecialPlace(i));
		m_SpecialPlaces.push_back(specialPlace);
	}
}
  
std::vector<std::shared_ptr<CRunway>> CModel::GetRunways() const
{
	return m_Runways;
}

std::vector<std::shared_ptr<CSpecialPlace>> CModel::GetSpecialPleces() const
{
	return m_SpecialPlaces;
}

std::shared_ptr<std::vector<std::shared_ptr<СTableRow>>> CModel::GetOutputData(std::vector<int>& unusedPlannedTakingOffMoments)
{
	// Создаем набор данных о ВС в формате строки таблицы
	auto tableRows = std::shared_ptr<std::vector<std::shared_ptr<СTableRow>>>(new std::vector<std::shared_ptr<СTableRow>>());

	// Получаем список ВС с заданными возможными и стартовыми моментами, упорядоченный по возможным моментам
	auto orderedConfiguredTakingOffAircrafts = GetOrderedConfiguredTakingOffAircrafts(unusedPlannedTakingOffMoments);

	// Задаем разрешенные моменты и резервные ВС в полученном списке ВС
	ReconfigureAircraftsWithReserve(*orderedConfiguredTakingOffAircrafts);

	// Для всех ВС задаем время простоя на ПРДВ
	SetPSWaitingTime(*orderedConfiguredTakingOffAircrafts);

	// Создаем список ВС, упорядоченных по разрешенным моментам
	auto aircraftsOrderedByPermittedMoments = CVectorHelper::Sort(*orderedConfiguredTakingOffAircrafts, CTakingOffAircraft::PermittedMomentComparer);

	// Заполняем набор данных о ВС
	for(auto aircraft : *aircraftsOrderedByPermittedMoments)
	{
		auto tableRow = GetTableRow(*aircraft);

		tableRows->push_back(tableRow);
	}

	// Возвращаем строки данных для таблицы
	return tableRows;
}


std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> CModel::GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments)
{
	// Создаем список ВС
	auto takingOffAircrafts = std::vector<std::shared_ptr<CTakingOffAircraft>>();
	// Создаем упорядоченный список плановых моментов на основе переданного списка
	auto orderedPlannedTakingOffMoments = CVectorHelper::Sort(plannedTakingOffMoments, CVectorHelper::AscendingComparer);

	int startDelay = 0;

	// Берем каждый плановый момент
	for (size_t i = 0; i < orderedPlannedTakingOffMoments->size(); i++)
	{
		// Генерируем входные данные для нового ВС
		auto inputData = m_AircraftInputDataGenerator->GetAircraftInputData((*orderedPlannedTakingOffMoments)[i]);
		// Создаем ВС
		auto takingOffAircraft = std::shared_ptr<CTakingOffAircraft>(new CTakingOffAircraft(*inputData));
		int startMoment;

		// Рассчитываем интервал взлета
		auto takingOffInterval = CInterval(takingOffAircraft->GetCreationMoments()->GetPlannedTakingOff() - 
			takingOffAircraft->GetCreationIntervals()->GetTakingOff(), takingOffAircraft->GetCreationMoments()->GetPlannedTakingOff());

		// Получаем задержку
		startDelay = GetRunwayStartDelay(takingOffAircraft, takingOffInterval);

		// Если нужна обработка
		if (takingOffAircraft->GetProcessingNecessity())
		{
			// Рассчитываем и задаем момент старта при необходимости обработки
			auto SPArriveMoment = takingOffInterval.GetStartMoment() - takingOffAircraft->GetCreationIntervals()->GetMotionFromPSToES() -
				takingOffAircraft->GetCreationIntervals()->GetMotionFromSPToPS() - takingOffAircraft->GetCreationIntervals()->GetProcessing();
			
			// Получаем задержку
			startDelay += GetSpecialPlaceStartDelay(*takingOffAircraft, takingOffInterval, SPArriveMoment);

			startMoment = SPArriveMoment - takingOffAircraft->GetCreationIntervals()->GetMotionFromParkingToSP() + 
				startDelay - CCommonInputData::GetSpareArrivalTimeInterval().GetEndMoment();
		}
		else
		{
			// Рассчитываем и задаем момент старта при отсутствии необходимости обработки
			startMoment = takingOffInterval.GetStartMoment() - takingOffAircraft->GetCreationIntervals()->GetMotionFromPSToES() -
				takingOffAircraft->GetCreationIntervals()->GetMotionFromParkingToPS() + startDelay - CCommonInputData::GetSpareArrivalTimeInterval().GetEndMoment();
		}

		// Задаем рассчитанный момент старта текущему ВС
		takingOffAircraft->GetCalculatingMoments()->SetStart(startMoment);
		// Рассчитываем и задаем возможный момент взлета
		takingOffAircraft->GetCalculatingMoments()->SetPossibleTakingOff(takingOffAircraft->GetCreationMoments()->GetPlannedTakingOff() + startDelay);

		takingOffAircrafts.push_back(takingOffAircraft);
	}

	// Упорядочиваем ВС по возможному моменту
	auto orderedTakingOffAircrafts = CVectorHelper::Sort(takingOffAircrafts, CTakingOffAircraft::PossibleMomentComparer);

	// Возвращаем упорядоченный список ВС
	return orderedTakingOffAircrafts;
}

/**
 * Возвращает задержку момента старта от ВПП.
 * 
 * \param takingOffAircraft
 * \param takingOffInterval
 * \return 
 */
int CModel::GetRunwayStartDelay(std::shared_ptr<CTakingOffAircraft> takingOffAircraft, CInterval& takingOffInterval) const
{
	// Находим ВПП, на которую движется ВС
	auto thisRunwayIterator = std::find_if(m_Runways.begin(), m_Runways.end(),
		[&takingOffAircraft](std::shared_ptr<CRunway> r) -> bool
		{
			auto temp = (*r).GetId() == takingOffAircraft->GetRunwayId();
			return (*r).GetId() == takingOffAircraft->GetRunwayId();
		});

	auto thisRunway = *thisRunwayIterator;

	// Получаем свободный интервал от ВПП
	auto freeRunwayInterval = thisRunway->GetFreeInterval(takingOffInterval);
	// Добавляем полученный новый интервал в ВПП
	thisRunway->AddAircraftInterval(takingOffAircraft->GetId(), *freeRunwayInterval);

	// Рассчитываем и возвращаем задержку
	return freeRunwayInterval->GetStartMoment() - takingOffInterval.GetStartMoment();
}


int CModel::GetSpecialPlaceStartDelay(CTakingOffAircraft& takingOffAircraft, int SPArriveMoment) const
{
	auto thisSpecialPlaceIterator = std::find_if(m_SpecialPlaces.begin(), m_SpecialPlaces.end(),
		[takingOffAircraft](std::shared_ptr<CSpecialPlace> sp) -> bool
		{
			return sp->GetId() == takingOffAircraft.GetSpecialPlaceId();
		}); 

	auto thisSpecialPlace = *thisSpecialPlaceIterator;

	auto processingInterval = CInterval(SPArriveMoment, SPArriveMoment + takingOffAircraft.GetCreationIntervals()->GetProcessing());
	auto freeSPInterval = thisSpecialPlace->GetFreeInterval(processingInterval);

	thisSpecialPlace->AddAircraftInterval(takingOffAircraft.GetId(), *freeSPInterval);

	return freeSPInterval->GetStartMoment() - processingInterval.GetStartMoment();
}


void CModel::ReconfigureAircraftsWithReserve(std::vector<std::shared_ptr<CTakingOffAircraft>>& orderedTakingOffAircrafts)
{
	// Создаем список использованных индексов
	auto usedIndexes = std::vector<int>();

	// Берем каждый ВС
	for (auto i = 0; i < (int)orderedTakingOffAircrafts.size(); i++)
	{
		// Проверяем, использовался ли уже этот индекс ВС
		if (CVectorHelper::Contains(usedIndexes, i))
			// Если да, то пропускаем его
			continue;

		// Если нет, то:

		// Получаем возможный момент ВС
		auto possibleMoment = orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->GetPossibleTakingOff();

		// Пытаемся получить ближайший к возможному моменту разрешенный момент
		auto nearestPermittedMoment = CCommonInputData::GetInputTakingOffMoments().GetNearestPermittedMoment(possibleMoment);
		// Проверяем 
		if (nearestPermittedMoment == nullptr)
		{
			// Если получили nullptr, значит разрешенный момент не найден
			// Отмечаем это соответствующим значением
			orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->SetStart(-1);
			orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->SetPermittedTakingOff(-1);
			// И пропускаем это  ВС
			continue;
		}

		// Если же получили не nullptr, то отмечаем, что это проверенный разрешенный момент
		auto verifiedPermittedMoment = *nearestPermittedMoment;

		// Рассчитываем задержку для текущего ВС, возможный момент которого мы рассматриваем
		auto startDelay = verifiedPermittedMoment - possibleMoment;
		// Рассчитываем момент старта для этого же ВС
		auto currentAircraftStartMoment = orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->GetStart() + startDelay;

		// Получаем список стартовых моментов для резервных ВС
		auto reserveAircraftStartMoments = GetReserveAircraftsStartMoments(verifiedPermittedMoment, i, orderedTakingOffAircrafts);

		// Создаем один общий список пар значений <индекс ВС : момент старта> для текущего и резервных ВС
		auto allAircraftsStartMomentData = std::map<int, int>{ { i, currentAircraftStartMoment } };
		for (auto item : *reserveAircraftStartMoments)
			allAircraftsStartMomentData.emplace(item.first, item.second);

		// Задаем моменты старта для текущего и резервных ВС
		SetSPreparedStartMoments(allAircraftsStartMomentData, orderedTakingOffAircrafts);

		// Получаем индекс ВС, имеющего наибольший приоритет (среди текущего и резервных ВС)
		auto mostPriorityAircraftIndex = GetMostPriorityAircraftIndex(allAircraftsStartMomentData, orderedTakingOffAircrafts);

		// Берем каждую пару значений из созданного общего списка ВС
		for(auto dataItem : allAircraftsStartMomentData)
		{
			// Задаем разрешенный момент
 			orderedTakingOffAircrafts.at(dataItem.first)->GetCalculatingMoments()->SetPermittedTakingOff(verifiedPermittedMoment);
			// Сравниваем индекс ВС и индекс наиболее приритетного ВС
			if (dataItem.first != mostPriorityAircraftIndex)
			{
				// Если данное ВС не является наиболее приоритетным => помечаем его как резервное
				orderedTakingOffAircrafts.at(dataItem.first)->SetReserveFlag(true);
				// Задаем резервный разрешенный момент (момент взлета, если это ВС останется резервным и не заменит главное ВС)
				orderedTakingOffAircrafts.at(dataItem.first)->GetCalculatingMoments()->SetReservePermittedTakingOff(CCommonInputData::GetInputTakingOffMoments()
					.GetNextPermittedMoment());
			}

			// Добавляем индекс текущего ВС в список использованных
			usedIndexes.push_back(dataItem.first);
		}
	}
}

std::shared_ptr<std::map<int, int>> CModel::GetReserveAircraftsStartMoments(int permittedMoment, int mainAircraftIndex,
	std::vector<std::shared_ptr<CTakingOffAircraft>>& orderedTakingOffAircrafts) const
{
	auto reserveStartMoments = std::shared_ptr<std::map<int, int>>(new std::map<int, int>());

	// Получаем список возможных моментов взлета
	auto possibleTakingOffMoments = std::vector<int>();
	for (auto aircraft : orderedTakingOffAircrafts)
		possibleTakingOffMoments.push_back(aircraft->GetCalculatingMoments()->GetPossibleTakingOff());

	// Проверяем, есть ли еще возможные моменты
	if (mainAircraftIndex < (int)possibleTakingOffMoments.size() - 1)
	{
		// Определяем допустимое количество резервных ВС
		auto reserveAircraftCount = GetReserveAircraftCount(permittedMoment, mainAircraftIndex, possibleTakingOffMoments);

		for (auto i = 1; i < reserveAircraftCount + 1; i++)
		{
			// Проверяем, есть ли еще возможные моменты и совпадают ли Id ВПП у ВС, которым принадлежат эти моменты
			if ((mainAircraftIndex + i < (int)possibleTakingOffMoments.size() &&
				orderedTakingOffAircrafts.at(mainAircraftIndex)->GetRunwayId() == orderedTakingOffAircrafts.at(mainAircraftIndex + i)->GetRunwayId()))
			{
				// Берем возможный момент для резервного ВС;
				auto reserveAircraftPossibleMoment = possibleTakingOffMoments[mainAircraftIndex + i];

				// Рассчитываем задержку для момента старта резервного ВС
				auto startDelay = permittedMoment - reserveAircraftPossibleMoment;
				// Задаем момент старта для резервного ВС
				auto reserveAircraftStartMoment = orderedTakingOffAircrafts.at(mainAircraftIndex + i)->GetCalculatingMoments()->GetStart() + startDelay;

				// Добавляем момент старта
				reserveStartMoments->emplace(mainAircraftIndex + i, reserveAircraftStartMoment);
			}
		}
	}

	// Возаращаем либо пустой список, либо заполненный старовыми моментами
	return reserveStartMoments;
}

int CModel::GetReserveAircraftCount(int permittedMoment, int aircraftIndex, std::vector<int>& possibleTakingOffMoments) const
{
	auto reserveAircraftCount = 0;

	auto index = 1;
	// Определяем максимально возможное количество резервных ВС.
	// Пока имеются возможные моменты и разрешенный момент входит в разрешенный страховочный интервал
	while (aircraftIndex + index < (int)possibleTakingOffMoments.size() - 1 &&
		permittedMoment - CCommonInputData::GetSpareArrivalTimeInterval().GetStartMoment() >= possibleTakingOffMoments[aircraftIndex + index])
	{
		// Увеличиваем количество резервных ВС
		reserveAircraftCount++;
		// Увеличиваем индекс
		index++;
	}

	// Проверяем полученное количество по заданному критерию
	int timeToLastTakingOffMoment;
	int permittedTime = 0;
	do
	{
		// По заданному критерию, в зависимости от определенного количества резервных ВС, находим допустимое время простоя резервных ВС
		auto permissibleReserveAircraftCountList = CCommonInputData::GetPermissibleReserveAircraftCount();
		for (auto it = permissibleReserveAircraftCountList.begin(); it != permissibleReserveAircraftCountList.end(); ++it)
		{
			if (reserveAircraftCount <= it->first)
			{
				permittedTime = (*it).second;
				break;
			}
		}

		// Рассчитываем время простоя (время, которое пройдет с момента взлета первого (основного) ВС до момента взлета последнего резервного ВС)
		timeToLastTakingOffMoment = possibleTakingOffMoments[aircraftIndex + reserveAircraftCount] - possibleTakingOffMoments[aircraftIndex];

		// Если рассчитанное время простоя больше допустимого => уменьшаем количество резервных ВС
		if (timeToLastTakingOffMoment > permittedTime)
			reserveAircraftCount--;

		// Повторяем, пока не удовлетровим заданному критерию
	} while (timeToLastTakingOffMoment > permittedTime);

	// Возвращаем количество резервных ВС
	return reserveAircraftCount;
}

void CModel::SetSPreparedStartMoments(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts)
{
	for (auto momentItem : aircraftsStartMomentData)
	{
		takingOffAircrafts[momentItem.first]->GetCalculatingMoments()->SetStart(momentItem.second);
	}
}

int CModel::GetMostPriorityAircraftIndex(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts) const
{
	auto mostPriorityAircraftIndex = aircraftsStartMomentData.begin()->first;
	for(auto dataItem : aircraftsStartMomentData)
	{
		if (takingOffAircrafts[dataItem.first]->GetPriority() > takingOffAircrafts[mostPriorityAircraftIndex]->GetPriority())
			mostPriorityAircraftIndex = dataItem.first;
	}

	return mostPriorityAircraftIndex;
}

void CModel::SetPSWaitingTime(std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts)
{
	for(auto aircraft : takingOffAircrafts)
	{
		// Рассчитываем момент прибытия на ПРДВ
		int arrivalToPSMoment;
		if (aircraft->GetProcessingNecessity())
		{
			arrivalToPSMoment = aircraft->GetCalculatingMoments()->GetStart() + aircraft->GetCreationIntervals()->GetMotionFromParkingToSP() + 
				aircraft->GetCreationIntervals()->GetProcessing() + aircraft->GetCreationIntervals()->GetMotionFromSPToPS();
		}
		else
			arrivalToPSMoment = aircraft->GetCalculatingMoments()->GetStart() + aircraft->GetCreationIntervals()->GetMotionFromParkingToPS();

		auto PSDelay1 = aircraft->GetCalculatingMoments()->GetReservePermittedTakingOff() - arrivalToPSMoment -
			aircraft->GetCreationIntervals()->GetMotionFromPSToES() - aircraft->GetCreationIntervals()->GetTakingOff();

		auto PSDelay2 = aircraft->GetCalculatingMoments()->GetPermittedTakingOff() - arrivalToPSMoment -
			aircraft->GetCreationIntervals()->GetMotionFromPSToES() - aircraft->GetCreationIntervals()->GetTakingOff();

		// Рассчитываем время простоя
		if (aircraft->GetReserveFlag())
			aircraft->GetCalculatingIntervals()->SetPSDelay(PSDelay1);
		else
			aircraft->GetCalculatingIntervals()->SetPSDelay(PSDelay2);
	}
}

std::shared_ptr<СTableRow> CModel::GetTableRow(CTakingOffAircraft& aircraft) const
{
	auto aircraftTotalMotionTime = aircraft.GetCreationIntervals()->GetTakingOff() + aircraft.GetCreationIntervals()->GetMotionFromPSToES();
	if (aircraft.GetProcessingNecessity())
		aircraftTotalMotionTime += aircraft.GetCreationIntervals()->GetMotionFromSPToPS() + aircraft.GetCreationIntervals()->GetMotionFromParkingToSP();
	else
		aircraftTotalMotionTime += aircraft.GetCreationIntervals()->GetMotionFromParkingToPS();

	auto permittedMoment = aircraft.GetCalculatingMoments()->GetPermittedTakingOff() != -1 ? std::to_string(aircraft.GetCalculatingMoments()->GetPermittedTakingOff()) : "Не найден";
	auto processingTime = aircraft.GetProcessingNecessity() ? std::to_string(aircraft.GetCreationIntervals()->GetProcessing()) : "-";
	auto specialPlaceId = aircraft.GetProcessingNecessity() ? std::to_string(aircraft.GetSpecialPlaceId()) : "-";

	return std::shared_ptr<СTableRow>(new СTableRow(std::to_string(aircraft.GetId()), std::to_string(aircraft.GetCreationMoments()->GetPlannedTakingOff()), 
		std::to_string(aircraft.GetCalculatingMoments()->GetPossibleTakingOff()), permittedMoment, std::to_string(aircraft.GetCalculatingMoments()->GetStart()), 
		std::to_string(aircraftTotalMotionTime), processingTime, aircraft.GetProcessingNecessity(), std::to_string(aircraft.GetPriority()), aircraft.GetReserveFlag(), 
		std::to_string(aircraft.GetCalculatingIntervals()->GetPSDelay()), aircraft.GetRunwayId(), specialPlaceId));
}
