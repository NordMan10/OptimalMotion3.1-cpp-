#include "../include/CTakingOffAircraft.h"
#include "../include/CProgramConstants.h"

CTakingOffAircraft::CTakingOffAircraft(const CAircraftInputData& inputData)
{
	m_Id = GetNewUniqueId();
	m_Type = inputData.GetType();
	m_Priority = inputData.GetPriority();
	m_RunwayId = inputData.GetRunwayId();
	m_SpecialPlaceId = inputData.GetSpecialPlaceId();
	m_CreationMoments = inputData.GetCreationMoments();
	m_CreationIntervals = inputData.GetCreationIntervals();
	m_ProcessingIsNeeded = inputData.GetProcessingNecessity();
}

int CTakingOffAircraft::ms_NextTakingOffAircraftId = CProgramConstants::ms_StartIdValue;


bool CTakingOffAircraft::PermittedMomentComparer(std::shared_ptr<CTakingOffAircraft> a1, std::shared_ptr<CTakingOffAircraft> a2)
{
	return a1->GetCalculatingMoments()->GetPermittedTakingOff() < a2->GetCalculatingMoments()->GetPermittedTakingOff();
}

bool CTakingOffAircraft::PossibleMomentComparer(std::shared_ptr<CTakingOffAircraft> a1, std::shared_ptr<CTakingOffAircraft> a2)
{
	return a1->GetCalculatingMoments()->GetPossibleTakingOff() < a2->GetCalculatingMoments()->GetPossibleTakingOff();
}

int CTakingOffAircraft::GetNewUniqueId()
{
	return ms_NextTakingOffAircraftId++;
}
