#include "../include/CSpecialPlace.h"

#include "../include/CIMassServiceZoneExtensions.h"

CSpecialPlace::CSpecialPlace(int id)
{
	m_Id = id;
}

int CSpecialPlace::GetId() const
{
	return m_Id;
}

void CSpecialPlace::AddAircraftInterval(int aircraftId, CInterval& freeInterval)
{
	CIMassServiceZoneExtensions::AddAircraftInterval(this, aircraftId, freeInterval, m_ProcessingIntervals);
}

std::shared_ptr<CInterval> CSpecialPlace::GetFreeInterval(CInterval& newInterval)
{
	return CIMassServiceZoneExtensions::GetFreeInterval(this, newInterval, m_ProcessingIntervals);
}

void CSpecialPlace::RemoveAircraftInterval(int aircraftId)
{
	CIMassServiceZoneExtensions::RemoveAircraftInterval(this, aircraftId, m_ProcessingIntervals);
}

void CSpecialPlace::Reset()
{
	m_ProcessingIntervals.clear();
}
