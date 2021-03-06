#include "../include/CTableRow.h"

CTableRow::CTableRow(std::string aircraftId, std::string plannedTakingOffMoment, std::string possibleTakingOffMoment, 
	std::string permittedTakingOffMoment, std::string startMoment, std::string totalMotionTime, std::string processingTime, 
	bool needProcessing, std::string prioriry, bool isReserved, std::string PSWaitingTime, std::string runwayId, std::string specialPlaceId)
{
	m_AircraftId = aircraftId;
	m_PossibleTakingOffMoment = possibleTakingOffMoment;
	m_PlannedTakingOffMoment = plannedTakingOffMoment;
	m_PermittedTakingOffMoment = permittedTakingOffMoment;
	m_StartMoment = startMoment;
	m_TotalMotionTime = totalMotionTime;
	m_ProcessingTime = processingTime;
	m_NeedProcessing = needProcessing;
	m_AircraftPriority = prioriry;
	m_IsReserved = isReserved;
	m_PSWaitingTime = PSWaitingTime;
	m_RunwayId = runwayId;
	m_SpecialPlaceId = specialPlaceId;
}
