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

std::shared_ptr<std::vector<std::shared_ptr<�TableRow>>> CModel::GetOutputData(std::vector<int>& unusedPlannedTakingOffMoments)
{
	// ������� ����� ������ � �� � ������� ������ �������
	auto tableRows = std::shared_ptr<std::vector<std::shared_ptr<�TableRow>>>(new std::vector<std::shared_ptr<�TableRow>>());

	// �������� ������ �� � ��������� ���������� � ���������� ���������, ������������� �� ��������� ��������
	auto orderedConfiguredTakingOffAircrafts = GetOrderedConfiguredTakingOffAircrafts(unusedPlannedTakingOffMoments);

	// ������ ����������� ������� � ��������� �� � ���������� ������ ��
	ReconfigureAircraftsWithReserve(*orderedConfiguredTakingOffAircrafts);

	// ��� ���� �� ������ ����� ������� �� ����
	SetPSWaitingTime(*orderedConfiguredTakingOffAircrafts);

	// ������� ������ ��, ������������� �� ����������� ��������
	auto aircraftsOrderedByPermittedMoments = CVectorHelper::Sort(*orderedConfiguredTakingOffAircrafts, CTakingOffAircraft::PermittedMomentComparer);

	// ��������� ����� ������ � ��
	for(auto aircraft : *aircraftsOrderedByPermittedMoments)
	{
		auto tableRow = GetTableRow(*aircraft);

		tableRows->push_back(tableRow);
	}

	// ���������� ������ ������ ��� �������
	return tableRows;
}


std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> CModel::GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments)
{
	// ������� ������ ��
	auto takingOffAircrafts = std::vector<std::shared_ptr<CTakingOffAircraft>>();
	// ������� ������������� ������ �������� �������� �� ������ ����������� ������
	auto orderedPlannedTakingOffMoments = CVectorHelper::Sort(plannedTakingOffMoments, CVectorHelper::AscendingComparer);

	int startDelay = 0;

	// ����� ������ �������� ������
	for (size_t i = 0; i < orderedPlannedTakingOffMoments->size(); i++)
	{
		// ���������� ������� ������ ��� ������ ��
		auto inputData = m_AircraftInputDataGenerator->GetAircraftInputData((*orderedPlannedTakingOffMoments)[i]);
		// ������� ��
		auto takingOffAircraft = std::shared_ptr<CTakingOffAircraft>(new CTakingOffAircraft(*inputData));
		int startMoment;

		// ������������ �������� ������
		auto takingOffInterval = CInterval(takingOffAircraft->GetCreationMoments()->GetPlannedTakingOff() - 
			takingOffAircraft->GetCreationIntervals()->GetTakingOff(), takingOffAircraft->GetCreationMoments()->GetPlannedTakingOff());

		// �������� ��������
		startDelay = GetRunwayStartDelay(takingOffAircraft, takingOffInterval);

		// ���� ����� ���������
		if (takingOffAircraft->GetProcessingNecessity())
		{
			// ������������ � ������ ������ ������ ��� ������������� ���������
			auto SPArriveMoment = takingOffInterval.GetStartMoment() - takingOffAircraft->GetCreationIntervals()->GetMotionFromPSToES() -
				takingOffAircraft->GetCreationIntervals()->GetMotionFromSPToPS() - takingOffAircraft->GetCreationIntervals()->GetProcessing();
			
			// �������� ��������
			startDelay += GetSpecialPlaceStartDelay(*takingOffAircraft, takingOffInterval, SPArriveMoment);

			startMoment = SPArriveMoment - takingOffAircraft->GetCreationIntervals()->GetMotionFromParkingToSP() + 
				startDelay - CCommonInputData::GetSpareArrivalTimeInterval().GetEndMoment();
		}
		else
		{
			// ������������ � ������ ������ ������ ��� ���������� ������������� ���������
			startMoment = takingOffInterval.GetStartMoment() - takingOffAircraft->GetCreationIntervals()->GetMotionFromPSToES() -
				takingOffAircraft->GetCreationIntervals()->GetMotionFromParkingToPS() + startDelay - CCommonInputData::GetSpareArrivalTimeInterval().GetEndMoment();
		}

		// ������ ������������ ������ ������ �������� ��
		takingOffAircraft->GetCalculatingMoments()->SetStart(startMoment);
		// ������������ � ������ ��������� ������ ������
		takingOffAircraft->GetCalculatingMoments()->SetPossibleTakingOff(takingOffAircraft->GetCreationMoments()->GetPlannedTakingOff() + startDelay);

		takingOffAircrafts.push_back(takingOffAircraft);
	}

	// ������������� �� �� ���������� �������
	auto orderedTakingOffAircrafts = CVectorHelper::Sort(takingOffAircrafts, CTakingOffAircraft::PossibleMomentComparer);

	// ���������� ������������� ������ ��
	return orderedTakingOffAircrafts;
}

/**
 * ���������� �������� ������� ������ �� ���.
 * 
 * \param takingOffAircraft
 * \param takingOffInterval
 * \return 
 */
int CModel::GetRunwayStartDelay(std::shared_ptr<CTakingOffAircraft> takingOffAircraft, CInterval& takingOffInterval) const
{
	// ������� ���, �� ������� �������� ��
	auto thisRunwayIterator = std::find_if(m_Runways.begin(), m_Runways.end(),
		[&takingOffAircraft](std::shared_ptr<CRunway> r) -> bool
		{
			auto temp = (*r).GetId() == takingOffAircraft->GetRunwayId();
			return (*r).GetId() == takingOffAircraft->GetRunwayId();
		});

	auto thisRunway = *thisRunwayIterator;

	// �������� ��������� �������� �� ���
	auto freeRunwayInterval = thisRunway->GetFreeInterval(takingOffInterval);
	// ��������� ���������� ����� �������� � ���
	thisRunway->AddAircraftInterval(takingOffAircraft->GetId(), *freeRunwayInterval);

	// ������������ � ���������� ��������
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
	// ������� ������ �������������� ��������
	auto usedIndexes = std::vector<int>();

	// ����� ������ ��
	for (auto i = 0; i < (int)orderedTakingOffAircrafts.size(); i++)
	{
		// ���������, ������������� �� ��� ���� ������ ��
		if (CVectorHelper::Contains(usedIndexes, i))
			// ���� ��, �� ���������� ���
			continue;

		// ���� ���, ��:

		// �������� ��������� ������ ��
		auto possibleMoment = orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->GetPossibleTakingOff();

		// �������� �������� ��������� � ���������� ������� ����������� ������
		auto nearestPermittedMoment = CCommonInputData::GetInputTakingOffMoments().GetNearestPermittedMoment(possibleMoment);
		// ��������� 
		if (nearestPermittedMoment == nullptr)
		{
			// ���� �������� nullptr, ������ ����������� ������ �� ������
			// �������� ��� ��������������� ���������
			orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->SetStart(-1);
			orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->SetPermittedTakingOff(-1);
			// � ���������� ���  ��
			continue;
		}

		// ���� �� �������� �� nullptr, �� ��������, ��� ��� ����������� ����������� ������
		auto verifiedPermittedMoment = *nearestPermittedMoment;

		// ������������ �������� ��� �������� ��, ��������� ������ �������� �� �������������
		auto startDelay = verifiedPermittedMoment - possibleMoment;
		// ������������ ������ ������ ��� ����� �� ��
		auto currentAircraftStartMoment = orderedTakingOffAircrafts.at(i)->GetCalculatingMoments()->GetStart() + startDelay;

		// �������� ������ ��������� �������� ��� ��������� ��
		auto reserveAircraftStartMoments = GetReserveAircraftsStartMoments(verifiedPermittedMoment, i, orderedTakingOffAircrafts);

		// ������� ���� ����� ������ ��� �������� <������ �� : ������ ������> ��� �������� � ��������� ��
		auto allAircraftsStartMomentData = std::map<int, int>{ { i, currentAircraftStartMoment } };
		for (auto item : *reserveAircraftStartMoments)
			allAircraftsStartMomentData.emplace(item.first, item.second);

		// ������ ������� ������ ��� �������� � ��������� ��
		SetSPreparedStartMoments(allAircraftsStartMomentData, orderedTakingOffAircrafts);

		// �������� ������ ��, �������� ���������� ��������� (����� �������� � ��������� ��)
		auto mostPriorityAircraftIndex = GetMostPriorityAircraftIndex(allAircraftsStartMomentData, orderedTakingOffAircrafts);

		// ����� ������ ���� �������� �� ���������� ������ ������ ��
		for(auto dataItem : allAircraftsStartMomentData)
		{
			// ������ ����������� ������
 			orderedTakingOffAircrafts.at(dataItem.first)->GetCalculatingMoments()->SetPermittedTakingOff(verifiedPermittedMoment);
			// ���������� ������ �� � ������ �������� ������������ ��
			if (dataItem.first != mostPriorityAircraftIndex)
			{
				// ���� ������ �� �� �������� �������� ������������ => �������� ��� ��� ���������
				orderedTakingOffAircrafts.at(dataItem.first)->SetReserveFlag(true);
				// ������ ��������� ����������� ������ (������ ������, ���� ��� �� ��������� ��������� � �� ������� ������� ��)
				orderedTakingOffAircrafts.at(dataItem.first)->GetCalculatingMoments()->SetReservePermittedTakingOff(CCommonInputData::GetInputTakingOffMoments()
					.GetNextPermittedMoment());
			}

			// ��������� ������ �������� �� � ������ ��������������
			usedIndexes.push_back(dataItem.first);
		}
	}
}

std::shared_ptr<std::map<int, int>> CModel::GetReserveAircraftsStartMoments(int permittedMoment, int mainAircraftIndex,
	std::vector<std::shared_ptr<CTakingOffAircraft>>& orderedTakingOffAircrafts) const
{
	auto reserveStartMoments = std::shared_ptr<std::map<int, int>>(new std::map<int, int>());

	// �������� ������ ��������� �������� ������
	auto possibleTakingOffMoments = std::vector<int>();
	for (auto aircraft : orderedTakingOffAircrafts)
		possibleTakingOffMoments.push_back(aircraft->GetCalculatingMoments()->GetPossibleTakingOff());

	// ���������, ���� �� ��� ��������� �������
	if (mainAircraftIndex < (int)possibleTakingOffMoments.size() - 1)
	{
		// ���������� ���������� ���������� ��������� ��
		auto reserveAircraftCount = GetReserveAircraftCount(permittedMoment, mainAircraftIndex, possibleTakingOffMoments);

		for (auto i = 1; i < reserveAircraftCount + 1; i++)
		{
			// ���������, ���� �� ��� ��������� ������� � ��������� �� Id ��� � ��, ������� ����������� ��� �������
			if ((mainAircraftIndex + i < (int)possibleTakingOffMoments.size() &&
				orderedTakingOffAircrafts.at(mainAircraftIndex)->GetRunwayId() == orderedTakingOffAircrafts.at(mainAircraftIndex + i)->GetRunwayId()))
			{
				// ����� ��������� ������ ��� ���������� ��;
				auto reserveAircraftPossibleMoment = possibleTakingOffMoments[mainAircraftIndex + i];

				// ������������ �������� ��� ������� ������ ���������� ��
				auto startDelay = permittedMoment - reserveAircraftPossibleMoment;
				// ������ ������ ������ ��� ���������� ��
				auto reserveAircraftStartMoment = orderedTakingOffAircrafts.at(mainAircraftIndex + i)->GetCalculatingMoments()->GetStart() + startDelay;

				// ��������� ������ ������
				reserveStartMoments->emplace(mainAircraftIndex + i, reserveAircraftStartMoment);
			}
		}
	}

	// ���������� ���� ������ ������, ���� ����������� ��������� ���������
	return reserveStartMoments;
}

int CModel::GetReserveAircraftCount(int permittedMoment, int aircraftIndex, std::vector<int>& possibleTakingOffMoments) const
{
	auto reserveAircraftCount = 0;

	auto index = 1;
	// ���������� ����������� ��������� ���������� ��������� ��.
	// ���� ������� ��������� ������� � ����������� ������ ������ � ����������� ������������ ��������
	while (aircraftIndex + index < (int)possibleTakingOffMoments.size() - 1 &&
		permittedMoment - CCommonInputData::GetSpareArrivalTimeInterval().GetStartMoment() >= possibleTakingOffMoments[aircraftIndex + index])
	{
		// ����������� ���������� ��������� ��
		reserveAircraftCount++;
		// ����������� ������
		index++;
	}

	// ��������� ���������� ���������� �� ��������� ��������
	int timeToLastTakingOffMoment;
	int permittedTime = 0;
	do
	{
		// �� ��������� ��������, � ����������� �� ������������� ���������� ��������� ��, ������� ���������� ����� ������� ��������� ��
		auto permissibleReserveAircraftCountList = CCommonInputData::GetPermissibleReserveAircraftCount();
		for (auto it = permissibleReserveAircraftCountList.begin(); it != permissibleReserveAircraftCountList.end(); ++it)
		{
			if (reserveAircraftCount <= it->first)
			{
				permittedTime = (*it).second;
				break;
			}
		}

		// ������������ ����� ������� (�����, ������� ������� � ������� ������ ������� (���������) �� �� ������� ������ ���������� ���������� ��)
		timeToLastTakingOffMoment = possibleTakingOffMoments[aircraftIndex + reserveAircraftCount] - possibleTakingOffMoments[aircraftIndex];

		// ���� ������������ ����� ������� ������ ����������� => ��������� ���������� ��������� ��
		if (timeToLastTakingOffMoment > permittedTime)
			reserveAircraftCount--;

		// ���������, ���� �� ������������ ��������� ��������
	} while (timeToLastTakingOffMoment > permittedTime);

	// ���������� ���������� ��������� ��
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
		// ������������ ������ �������� �� ����
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

		// ������������ ����� �������
		if (aircraft->GetReserveFlag())
			aircraft->GetCalculatingIntervals()->SetPSDelay(PSDelay1);
		else
			aircraft->GetCalculatingIntervals()->SetPSDelay(PSDelay2);
	}
}

std::shared_ptr<�TableRow> CModel::GetTableRow(CTakingOffAircraft& aircraft) const
{
	auto aircraftTotalMotionTime = aircraft.GetCreationIntervals()->GetTakingOff() + aircraft.GetCreationIntervals()->GetMotionFromPSToES();
	if (aircraft.GetProcessingNecessity())
		aircraftTotalMotionTime += aircraft.GetCreationIntervals()->GetMotionFromSPToPS() + aircraft.GetCreationIntervals()->GetMotionFromParkingToSP();
	else
		aircraftTotalMotionTime += aircraft.GetCreationIntervals()->GetMotionFromParkingToPS();

	auto permittedMoment = aircraft.GetCalculatingMoments()->GetPermittedTakingOff() != -1 ? std::to_string(aircraft.GetCalculatingMoments()->GetPermittedTakingOff()) : "�� ������";
	auto processingTime = aircraft.GetProcessingNecessity() ? std::to_string(aircraft.GetCreationIntervals()->GetProcessing()) : "-";
	auto specialPlaceId = aircraft.GetProcessingNecessity() ? std::to_string(aircraft.GetSpecialPlaceId()) : "-";

	return std::shared_ptr<�TableRow>(new �TableRow(std::to_string(aircraft.GetId()), std::to_string(aircraft.GetCreationMoments()->GetPlannedTakingOff()), 
		std::to_string(aircraft.GetCalculatingMoments()->GetPossibleTakingOff()), permittedMoment, std::to_string(aircraft.GetCalculatingMoments()->GetStart()), 
		std::to_string(aircraftTotalMotionTime), processingTime, aircraft.GetProcessingNecessity(), std::to_string(aircraft.GetPriority()), aircraft.GetReserveFlag(), 
		std::to_string(aircraft.GetCalculatingIntervals()->GetPSDelay()), aircraft.GetRunwayId(), specialPlaceId));
}
