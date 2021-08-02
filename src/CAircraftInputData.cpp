#include "../include/CAircraftInputData.h"

CAircraftInputData::CAircraftInputData(std::string runwayId, int specialPlaceId, std::string type,
	int priority, bool processingIsNeeded, std::shared_ptr<CTakingOffAircraftCreationMoments> creationMoments,
	std::shared_ptr<CTakingOffAircraftCreationIntervals> creationIntervals)
	: m_RunwayId(runwayId), m_SpecialPlaceId(specialPlaceId), m_Type(type), m_Priority(priority), 
	m_ProcessingIsNeeded(processingIsNeeded), m_CreationMoments(creationMoments), m_CreationIntervals(creationIntervals)
{

}

