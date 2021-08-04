#include "../include/CIMassServiceZoneExtensions.h"
#include <stdexcept>

void CIMassServiceZoneExtensions::AddAircraftInterval(IMassServiceZone* zone, int aircraftId, const CInterval freeInterval, std::map<int, CInterval>& zoneIntervals)
{
	if (CheckIntervalsIntersection(freeInterval, zoneIntervals))
		throw std::runtime_error("Интервалы пересекаются! Передайте проверенный интервал");

	// ? Если данная ошибка возникла, значит метод 
	// ? выдачи свободного интервала GetFreeInterval() работает не правильно

	zoneIntervals.emplace(aircraftId, freeInterval);
}

std::shared_ptr<CInterval> CIMassServiceZoneExtensions::GetFreeInterval(IMassServiceZone* zone, const CInterval& interval, const std::map<int, CInterval>& zoneIntervals)
{
	auto newInterval = new CInterval(interval.m_StartMoment, interval.m_EndMoment);

	//CInterval* resultIntervalPtr = nullptr;

	for(const auto& occupiedInterval : zoneIntervals)
	{
		if (newInterval->m_EndMoment >= occupiedInterval.second.m_StartMoment && newInterval->m_StartMoment <= occupiedInterval.second.m_EndMoment)
		{
			auto delay = occupiedInterval.second.m_EndMoment - interval.m_StartMoment;
			newInterval = new CInterval(interval.m_StartMoment + delay, interval.m_EndMoment + delay);
		}
	}

	return std::shared_ptr<CInterval>(newInterval);
}

void CIMassServiceZoneExtensions::RemoveAircraftInterval(IMassServiceZone* zone, int aircraftId, std::map<int, CInterval>& zoneIntervals)
{
	zoneIntervals.erase(aircraftId);
}

bool CIMassServiceZoneExtensions::CheckIntervalsIntersection(const CInterval& interval, const std::map<int, CInterval>& zoneIntervals)
{
	for(const auto& occupiedInterval : zoneIntervals)
	{
		auto zoneInterval = occupiedInterval.second;
		if (zoneInterval.IsIntervalsIntersects(interval))
			return true;
	}

	return false;
}