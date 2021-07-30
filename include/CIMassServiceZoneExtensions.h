#pragma once

/** Крaткое описание класса
 * Класс, содержащий реализацию общих методов для интерфейса зоны массового обслуживания (IMassServiceZone).
   Описание данного интерфейса см. в определении интерфейса IMassServiceZone
 * 
 * File  : CIMassServiceZoneExtensions.h
 * Author:
 *
 * Длинное описание класса
 *
 */
 // SYSTEM INCLUDES
 //	
#include <map>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "IMassServiceZone.h"
#include "CInterval.h"


class CIMassServiceZoneExtensions
{
public:
	static void AddAircraftInterval(int aircraftId, const CInterval& freeInterval, std::map<int, CInterval>& zoneIntervals);

	static std::shared_ptr<CInterval> GetFreeInterval(const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);

	static void RemoveAircraftInterval(int aircraftId, std::map<int, CInterval>& zoneIntervals);

private:
	static bool CheckIntervalsIntersection(const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);
};

