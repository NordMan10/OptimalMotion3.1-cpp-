#include "../include/CTakingOffAircraftCreationMoments.h"

CTakingOffAircraftCreationMoments::CTakingOffAircraftCreationMoments(int plannedTakingOff)
{
	m_PlannedTakingOff = plannedTakingOff;
}

int CTakingOffAircraftCreationMoments::GetPlannedTakingOff() const
{
	return m_PlannedTakingOff;
}
