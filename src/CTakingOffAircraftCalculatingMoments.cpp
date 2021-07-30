#include "../include/CTakingOffAircraftCalculatingMoments.h"

int CTakingOffAircraftCalculatingMoments::GetPossibleTakingOff() const
{
	return m_PossibleTakingOff;
}

int CTakingOffAircraftCalculatingMoments::GetPermittedTakingOff() const
{
	return m_PermittedTakingOff;
}

int CTakingOffAircraftCalculatingMoments::GetReservePermittedTakingOff() const
{
	return m_ReservePermittedTakingOff;
}

int CTakingOffAircraftCalculatingMoments::GetStart() const
{
	return m_Start;
}