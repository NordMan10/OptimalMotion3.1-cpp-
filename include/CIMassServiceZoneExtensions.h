#pragma once

/** ��a���� �������� ������
 * �����, ���������� ���������� ����� ������� ��� ���������� IMassServiceZone
 * 
 * File  : CIMassServiceZoneExtensions.h
 * Author: Yury Ten
 *
 * ������� �������� ������
 * �����, ���������� ���������� ����� ������� ��� ���������� ���� ��������� ������������ (IMassServiceZone).
   �������� ������� ���������� ��. � ����������� ���������� IMassServiceZone
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
	/**
	 * ��������� ���������� �������� � ������ ���������� ����, ���� �� �� ������������ � ������������� �����������.
	 * ���������������, ��� ��� ������� ��������� (�� �������������� ��������), ������� ��� ��������� ������� GetFreeInterval().
	 * 
	 * \param zone ���� ��������� ������������ IMassServiceZone
	 * \param aircraftId Id ��
	 * \param freeInterval ������������ ��������� ��������
	 * \param zoneIntervals ������ ������������ ���������� ����
	 */
	static void AddAircraftInterval(IMassServiceZone* zone, int aircraftId, const CInterval& freeInterval, std::map<int, CInterval>& zoneIntervals);

	/**
	 * ���������, ����� �� �������� ���������� �������� � ������ ��� ������������ ���������� ���� ��� ����������� � ����.
	 * ���� �����, �� ���������� ����� ����������� ���������. ���� ������, �� ������������ �����, ���������������� ��������.
	 * 
	 * \param zone ���� ��������� ������������.
	 * \param interval ��������, ������� ����� ���������.
	 * \param zoneIntervals ������ ������������ ���������� ����.
	 * \return ���������, ���������������� � ������������� ����������� ����, ��������.
	 */
	static std::shared_ptr<CInterval> GetFreeInterval(IMassServiceZone* zone, const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);

	/**
	 * ������� �� ������ ���������� ��������� ���� ��������, ������������� ��, Id �������� ��� �������.
	 * 
	 * \param zone ���� ��������� ������������.
	 * \param aircraftId Id ��, �������� �������� ����� �������.
	 * \param zoneIntervals ������ ������������ ���������� ����.
	 */
	static void RemoveAircraftInterval(IMassServiceZone* zone, int aircraftId, std::map<int, CInterval>& zoneIntervals);

private:
	/**
	 * ��������� ����������� ����������� ��������� � ������� ������������ ����������.
	 * 
	 * \param interval ��������, ������� ����� ���������.
	 * \param zoneIntervals ������ ������������ ���������� ����.
	 * \return �������� bool, ������������ ������� �����������.
	 */
	static bool CheckIntervalsIntersection(const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);
};

