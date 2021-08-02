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

std::shared_ptr<std::vector<std::shared_ptr<�TableRow>>> CModel::GetOutputData(std::vector<int>& unusedPlannedTakingOffMoments)
{
	auto tableRows = std::shared_ptr<std::vector<std::shared_ptr<�TableRow>>>{};

	// �������� ������ �� � ��������� ���������� � ���������� ���������, ������������� �� ��������� ��������
	auto orderedConfiguredTakingOffAircrafts = GetOrderedConfiguredTakingOffAircrafts(unusedPlannedTakingOffMoments);

	// �������� ������ �� � ��������� ���������� ��
	auto aircraftsWithReserve = GetReconfiguredAircraftsWithReserve(*orderedConfiguredTakingOffAircrafts);

	// ��� ���� �� ������ ����� ������� �� ����
	SetPSWaitingTime(aircraftsWithReserve);	

	// ������� ������ ��, ������������� �� ����������� ��������
	auto aircraftsOrderedByPermittedMoments = CVectorHelper::Sort(aircraftsWithReserve, CTakingOffAircraft::PermittedMomentComparer);

	// ��������� ������ � ������ �� � �������
	for(auto aircraft : *aircraftsOrderedByPermittedMoments)
	{
		auto tableRow = GetTableRow(aircraft);

		(*tableRows).push_back(tableRow);
	}

	// ���������� ������ ������ ��� �������
	return tableRows;
}

std::shared_ptr<std::vector<CTakingOffAircraft>> CModel::GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments)
{
	// ������� ������ ��
	auto takingOffAircrafts = std::vector<CTakingOffAircraft>();
	// ������� ������������� ������ �������� �������� �� ������ ����������� ������
	auto orderedPlannedTakingOffMoments = CVectorHelper::Sort(plannedTakingOffMoments, CVectorHelper::AscendingComparer);

	int startDelay = 0;

	// ����� ������ �������� ������
	for (auto i = 0; i < orderedPlannedTakingOffMoments->size(); i++)
	{
		// ���������� ������� ������ ��� ������ ��
		auto inputData = m_AircraftInputDataGenerator->GetAircraftInputData((*orderedPlannedTakingOffMoments)[i]);
		// ������� ��
		auto takingOffAircraft = CTakingOffAircraft(*inputData);
		int startMoment;

		// ������������ �������� ������
		auto takingOffInterval = CInterval(inputData->m_CreationMoments.GetPlannedTakingOff() - takingOffAircraft.m_CreationIntervals->GetTakingOff(),
			inputData->m_CreationMoments.GetPlannedTakingOff());

		// �������� ��������
		startDelay = GetRunwayStartDelay(takingOffAircraft, takingOffInterval);

		// ���� ����� ���������
		if (takingOffAircraft.ProcessingIsNeeded)
		{
			// �������� ��������
			startDelay += GetSpecialPlaceStartDelay(takingOffAircraft, takingOffInterval);

			// ������������ � ������ ������ ������ ��� ������������� ���������
			var SPArriveMoment = takingOffInterval.StartMoment - takingOffAircraft.CreationIntervals.MotionFromPSToES -
				takingOffAircraft.CreationIntervals.MotionFromSPToPS - takingOffAircraft.CreationIntervals.Processing;

			startMoment = SPArriveMoment - takingOffAircraft.CreationIntervals.MotionFromParkingToSP + startDelay - CommonInputData.SpareArrivalTimeInterval.EndMoment;
		}
		else
		{
			// ������������ � ������ ������ ������ ��� ���������� ������������� ���������
			startMoment = takingOffInterval.StartMoment - takingOffAircraft.CreationIntervals.MotionFromPSToES - takingOffAircraft.CreationIntervals.MotionFromParkingToPS +
				startDelay - CommonInputData.SpareArrivalTimeInterval.EndMoment;
		}

		// ������ ������������ ������ ������ �������� ��
		takingOffAircraft.CalculatingMoments.Start = startMoment;
		// ������������ � ������ ��������� ������ ������
		takingOffAircraft.CalculatingMoments.PossibleTakingOff = takingOffAircraft.CreationMoments.PlannedTakingOff + startDelay;

		takingOffAircrafts.Add(takingOffAircraft);
	}
}

/**
 * ���������� �������� ������� ������ �� ���.
 * 
 * \param takingOffAircraft
 * \param takingOffInterval
 * \return 
 */
int CModel::GetRunwayStartDelay(CTakingOffAircraft& takingOffAircraft, CInterval& takingOffInterval)
{
	// ������� ���, �� ������� �������� ��
	auto thisRunwayIterator = std::find_if(m_Runways.begin(), m_Runways.end(),
		[&takingOffAircraft](std::shared_ptr<CRunway> r) -> bool
		{
			return (*r).GetId() == takingOffAircraft.GetRunwayId();
		});

	

	auto thisRunway = *thisRunwayIterator;

	// �������� ��������� �������� �� ���
	auto freeRunwayInterval = thisRunway->GetFreeInterval(takingOffInterval);
	// ��������� ���������� ����� �������� � ���
	thisRunway->AddAircraftInterval(takingOffAircraft.GetId(), *freeRunwayInterval);

	// ������������ � ���������� ��������
	return freeRunwayInterval->m_StartMoment - takingOffInterval.m_StartMoment;
}
