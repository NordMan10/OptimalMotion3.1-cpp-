#include "../include/CTakingOffAircraft.h"
#include "../include/CProgramConstants.h"

CTakingOffAircraft::CTakingOffAircraft(const CAircraftInputData& inputData)
{
	m_Id = ms_IdGenerator++;
	m_Type = inputData.m_Type;
	m_Priority = inputData.m_Priority;
	m_CreationMoments = inputData.m_CreationMoments;
	m_CreationIntervals = inputData.m_CreationIntervals;
	m_ProcessingIsNeeded = inputData.m_ProcessingIsNeeded;
	m_RunwayId = inputData.m_RunwayId;
	m_SpecialPlaceId = inputData.m_SpecialPlaceId;
}

int CTakingOffAircraft::ms_IdGenerator = CProgramConstants::m_StartIdValue;
