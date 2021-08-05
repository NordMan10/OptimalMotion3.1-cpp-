#pragma once

/** ��a���� �������� ������
 * ����� ��� ����� ������� ������
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
	static int ms_RunwayCount;

	static int ms_SpecialPlaceCount;

	static CInputTakingOffMoments ms_InputTakingOffMoments;

	static CInterval ms_SpareArrivalTimeInterval;

	static std::map<int, int> ms_PermissibleReserveAircraftCount;

	/// <summary>
	/// ���������� ���
	/// </summary>
public:
	static int GetRunwayCount();
	static void SetRunwayCount(int value);

	/// <summary>
	/// ���������� ����. ��������
	/// </summary>
	static int GetSpecialPlaceCount();
	static void SetSpecialPlaceCount(int value);

	/// <summary>
	/// ������ �������� � ����������� ��������
	/// </summary>
	static CInputTakingOffMoments& GetInputTakingOffMoments();

	/// <summary>
	///  �������� ��������� ������� ��������
	/// </summary>
	static CInterval& GetSpareArrivalTimeInterval();
	static void SetSpareArrivalTimeInterval(CInterval& value);

	/// <summary>
	/// ���������� ���������� ��������� �� � ����������� �� ������� �������
	/// </summary>
	static std::map<int, int>& GetPermissibleReserveAircraftCount();
};
