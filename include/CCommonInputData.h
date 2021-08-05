#pragma once

/** ��a���� �������� ������
 * ����� ��� �������� ������, ����� ��� ���� ���������
 * File  : CCommonInputData.h
 * Author: Yury Ten
 *
 * ������� �������� ������
 *
 */

 // SYSTEM INCLUDES
#include <map>

// LOCAL INCLUDES
#include "./CInputTakingOffMoments.h"
#include "CInterval.h"
#include <memory>


class CCommonInputData final
{
private:
	/**
	 * ���������� ���.
	 */
	static int ms_RunwayCount;

	/**
	 * ���������� ����. ��������.
	 */
	static int ms_SpecialPlaceCount;

	/**
	 * ������ ����������� � �������� �������� ��� ������������� ������ CInputTakingOffMoments.
	 */
	static std::vector<int> ms_PlannedMoments;
	static std::vector<int> ms_PermittedMoments;

	/**
	 * ����� � �������� �������� � ����������� �������� � �������� ������ � ����
	 */
	static CInputTakingOffMoments ms_InputTakingOffMoments;

	/**
	 * �������� ��������� ������� ��������.
	 */
	static CInterval ms_SpareArrivalTimeInterval;

	/**
	 * ���������� ���������� ��������� �� � ����������� �� ������� �������.
	 */
	static std::map<int, int> ms_PermissibleReserveAircraftCount;

	
public:
	static int GetRunwayCount();
	static void SetRunwayCount(int value);

	static int GetSpecialPlaceCount();
	static void SetSpecialPlaceCount(int value);

	static CInputTakingOffMoments& GetInputTakingOffMoments();

	static CInterval& GetSpareArrivalTimeInterval();
	static void SetSpareArrivalTimeInterval(CInterval& value);

	static std::map<int, int>& GetPermissibleReserveAircraftCount();
};
