#include <algorithm>
#include "../include/CModel.h"
#include "../include/CProgramConstants.h"
#include "../include/CVectorHelper.h"

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
	auto tableRows = std::shared_ptr<std::vector<std::shared_ptr<СTableRow>>>{};

	// Получаем список ВС с заданными возможными и стартовыми моментами, упорядоченный по возможным моментам
	auto orderedConfiguredTakingOffAircrafts = GetOrderedConfiguredTakingOffAircrafts(unusedPlannedTakingOffMoments);

	// Получаем список ВС с заданными резервными ВС
	auto aircraftsWithReserve = GetReconfiguredAircraftsWithReserve(*orderedConfiguredTakingOffAircrafts);

	// Для всех ВС задаем время простоя на ПРДВ
	SetPSWaitingTime(aircraftsWithReserve);	

	// Создаем список ВС, упорядоченных по разрешенным моментам
	auto aircraftsOrderedByPermittedMoments = CVectorHelper::Sort(aircraftsWithReserve, CTakingOffAircraft::PermittedMomentComparer);

	// Добавляем данные о каждом ВС в таблицу
	for(auto aircraft : *aircraftsOrderedByPermittedMoments)
	{
		auto tableRow = GetTableRow(aircraft);

		(*tableRows).push_back(tableRow);
	}

	// Возвращаем строки данных для таблицы
	return tableRows;
}

std::shared_ptr<std::vector<CTakingOffAircraft>> CModel::GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments)
{
	// Создаем список ВС
	auto takingOffAircrafts = std::vector<CTakingOffAircraft>();
	// Создаем упорядоченный список плановых моментов на основе переданного списка
	auto orderedPlannedTakingOffMoments = CVectorHelper::Sort(plannedTakingOffMoments, CVectorHelper::AscendingComparer);

	int startDelay = 0;

	// Берем каждый плановый момент
	for (auto i = 0; i < orderedPlannedTakingOffMoments->size(); i++)
	{
		// Генерируем входные данные для нового ВС
		auto inputData = m_AircraftInputDataGenerator->GetAircraftInputData((*orderedPlannedTakingOffMoments)[i]);
		// Создаем ВС
		auto takingOffAircraft = CTakingOffAircraft(*inputData);
		int startMoment;

		// Рассчитываем интервал взлета
		auto takingOffInterval = CInterval(inputData->m_CreationMoments.GetPlannedTakingOff() - takingOffAircraft.m_CreationIntervals->GetTakingOff(),
			inputData->m_CreationMoments.GetPlannedTakingOff());

		// Получаем задержку
		startDelay = GetRunwayStartDelay(takingOffAircraft, takingOffInterval);

		// Если нужна обработка
		if (takingOffAircraft.ProcessingIsNeeded)
		{
			// Получаем задержку
			startDelay += GetSpecialPlaceStartDelay(takingOffAircraft, takingOffInterval);

			// Рассчитываем и задаем момент старта при необходимости обработки
			var SPArriveMoment = takingOffInterval.StartMoment - takingOffAircraft.CreationIntervals.MotionFromPSToES -
				takingOffAircraft.CreationIntervals.MotionFromSPToPS - takingOffAircraft.CreationIntervals.Processing;

			startMoment = SPArriveMoment - takingOffAircraft.CreationIntervals.MotionFromParkingToSP + startDelay - CommonInputData.SpareArrivalTimeInterval.EndMoment;
		}
		else
		{
			// Рассчитываем и задаем момент старта при отсутствии необходимости обработки
			startMoment = takingOffInterval.StartMoment - takingOffAircraft.CreationIntervals.MotionFromPSToES - takingOffAircraft.CreationIntervals.MotionFromParkingToPS +
				startDelay - CommonInputData.SpareArrivalTimeInterval.EndMoment;
		}

		// Задаем рассчитанный момент старта текущему ВС
		takingOffAircraft.CalculatingMoments.Start = startMoment;
		// Рассчитываем и задаем возможный момент взлета
		takingOffAircraft.CalculatingMoments.PossibleTakingOff = takingOffAircraft.CreationMoments.PlannedTakingOff + startDelay;

		takingOffAircrafts.Add(takingOffAircraft);
	}
}

/**
 * Возвращает задержку момента старта от ВПП.
 * 
 * \param takingOffAircraft
 * \param takingOffInterval
 * \return 
 */
int CModel::GetRunwayStartDelay(CTakingOffAircraft& takingOffAircraft, CInterval& takingOffInterval)
{
	// Находим ВПП, на которую движется ВС
	auto thisRunwayIterator = std::find_if(m_Runways.begin(), m_Runways.end(),
		[&takingOffAircraft](std::shared_ptr<CRunway> r) -> bool
		{
			return (*r).GetId() == takingOffAircraft.GetRunwayId();
		});

	

	auto thisRunway = *thisRunwayIterator;

	// Получаем свободный интервал от ВПП
	auto freeRunwayInterval = thisRunway->GetFreeInterval(takingOffInterval);
	// Добавляем полученный новый интервал в ВПП
	thisRunway->AddAircraftInterval(takingOffAircraft.GetId(), *freeRunwayInterval);

	// Рассчитываем и возвращаем задержку
	return freeRunwayInterval->m_StartMoment - takingOffInterval.m_StartMoment;
}
