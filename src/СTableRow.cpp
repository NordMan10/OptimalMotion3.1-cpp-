#include "../include/ÑTableRow.h"

ÑTableRow::ÑTableRow(std::string aircraftId, std::string plannedTakingOffMoment, std::string possibleTakingOffMoment, 
	std::string permittedTakingOffMoment, std::string startMoment, std::string totalMotionTime, std::string processingTime, 
	bool needProcessing, std::string prioriry, bool isReserved, std::string m_PSWaitingTime, std::string runwayId, std::string specialPlaceId)
{
	m_AircraftId = aircraftId;
	m_PossibleTakingOffMoment = possibleTakingOffMoment;
	m_PlannedTakingOffMoment = plannedTakingOffMoment;
	m_PermittedTakingOffMoment = permittedTakingOffMoment;
	m_StartMoment = startMoment;
	m_TotalMotionTime = totalMotionTime;
	ms_ProcessingTime = processingTime;
	m_NeedProcessing = needProcessing;
	m_AircraftPriority = prioriry;
	m_IsReserved = isReserved;
	m_PSWaitingTime = m_PSWaitingTime;
	m_RunwayId = runwayId;
	m_SpecialPlaceId = specialPlaceId;
}
