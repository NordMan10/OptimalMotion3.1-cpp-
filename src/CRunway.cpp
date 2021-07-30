#include "../include/CRunway.h"

#include "../include/CIMassServiceZoneExtensions.h"

CRunway::CRunway(int id)
{
	m_Id = id;
}

int CRunway::GetId() const
{
	return m_Id;
}

void CRunway::AddAircraftInterval(int aircraftId, CInterval& freeInterval)
{
	CIMassServiceZoneExtensions::AddAircraftInterval(this, aircraftId, freeInterval, m_OccupiedIntervals);
}

std::shared_ptr<CInterval> CRunway::GetFreeInterval(CInterval& newInterval)
{
	return CIMassServiceZoneExtensions::GetFreeInterval(this, newInterval, m_OccupiedIntervals);
}

void CRunway::RemoveAircraftInterval(int aircraftId)
{
	CIMassServiceZoneExtensions::RemoveAircraftInterval(this, aircraftId, m_OccupiedIntervals);
}

void CRunway::Reset()
{
	m_OccupiedIntervals.clear();
}