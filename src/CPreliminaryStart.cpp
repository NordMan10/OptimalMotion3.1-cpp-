#include "../include/CPreliminaryStart.h"
#include "../include/CIMassServiceZoneExtensions.h"

CPreliminaryStart::CPreliminaryStart(int id)
{
	m_Id = id;
}

int CPreliminaryStart::GetId() const
{
	return m_Id;
}

void CPreliminaryStart::AddAircraftInterval(int aircraftId, CInterval& freeInterval)
{
	CIMassServiceZoneExtensions::AddAircraftInterval(this, aircraftId, freeInterval, m_OccupiedIntervals);
}

std::shared_ptr<CInterval> CPreliminaryStart::GetFreeInterval(CInterval& newInterval)
{
	return CIMassServiceZoneExtensions::GetFreeInterval(this, newInterval, m_OccupiedIntervals);
}

void CPreliminaryStart::RemoveAircraftInterval(int aircraftId)
{
	CIMassServiceZoneExtensions::RemoveAircraftInterval(this, aircraftId, m_OccupiedIntervals);
}

void CPreliminaryStart::Reset()
{
	m_OccupiedIntervals.clear();
}
