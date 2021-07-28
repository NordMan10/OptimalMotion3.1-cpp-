#include "../include/CAircraftInputData.h"

CAircraftInputData::CAircraftInputData(std::string runwayId, int specialPlaceId, std::string type,
	int priority, bool processingIsNeeded, CTakingOffAircraftCreationIntervals& creationIntervals,
	CTakingOffAircraftCreationMoments& creationMoments)
{
	m_RunwayId = runwayId;
	m_SpecialPlaceId = specialPlaceId;
	m_Type = type;
	m_Priority = priority;
	m_ProcessingIsNeeded = processingIsNeeded;
	m_CreationIntervals = creationIntervals;
	m_CreationMoments = creationMoments;
}
