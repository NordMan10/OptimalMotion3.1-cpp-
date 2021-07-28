#include "../include/CIMassServiceZoneExtensions.h"
#include <stdexcept>

void CIMassServiceZoneExtensions::AddAircraftInterval(int aircraftId, const CInterval& freeInterval, std::map<int, CInterval>& zoneIntervals)
{
	//try
	//{
		if (CheckIntervalsIntersection(freeInterval, zoneIntervals))
			throw std::runtime_error("Интервалы пересекаются! Передайте проверенный интервал");
	//}
	//catch (std::exception& exception)
	//{
		// ? Здесь нужно реализовать уведомление об ошибке. Если она возникла, значит метод 
		// ? выдачи свободного интервала (GetFreeInterval()) работает не правильно
	//	//cerr << exception.what() << endl;
	//}

	zoneIntervals.emplace(aircraftId, freeInterval);
}

CInterval CIMassServiceZoneExtensions::GetFreeInterval(const CInterval& interval, const std::map<int, CInterval>& zoneIntervals)
{
	auto newInterval = CInterval(interval.m_StartMoment, interval.m_EndMoment);
	for(const auto& occupiedInterval : zoneIntervals)
	{
		if (newInterval.m_EndMoment >= occupiedInterval.second.m_StartMoment && newInterval.m_StartMoment <= occupiedInterval.second.m_EndMoment)
		{
			auto delay = occupiedInterval.second.m_EndMoment - interval.m_StartMoment;
			newInterval = CInterval(interval.m_StartMoment + delay, interval.m_EndMoment + delay);
		}
	}

	return newInterval;
}

void CIMassServiceZoneExtensions::RemoveAircraftInterval(int aircraftId, std::map<int, CInterval>& zoneIntervals)
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