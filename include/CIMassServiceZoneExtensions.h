#pragma once

/** ��a���� �������� ������
 * �����, ���������� ���������� ����� ������� ��� ���������� ���� ��������� ������������ (IMassServiceZone).
   �������� ������� ���������� ��. � ����������� ���������� IMassServiceZone
 * 
 * File  : CIMassServiceZoneExtensions.h
 * Author:
 *
 * ������� �������� ������
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

