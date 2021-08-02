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
	static CInputTakingOffMoments* GetInputTakingOffMoments();

	/// <summary>
	///  �������� ��������� ������� ��������
	/// </summary>
	static CInterval* GetSpareArrivalTimeInterval();
	static void SetSpareArrivalTimeInterval(CInterval* value);

	/// <summary>
	/// ���������� ���������� ��������� �� � ����������� �� ������� �������
	/// </summary>
	static std::map<int, int> GetPermissibleReserveAircraftCount();
};


//class CCommonInputData
//{
//public:
//	static int ms_RunwayCount;
//
//	static int ms_SpecialPlaceCount;
//
//	static std::shared_ptr<CInputTakingOffMoments> ms_InputTakingOffMoments;
//
//	CInterval ms_SpareArrivalTimeInterval;
//
//	map<int, int> ms_PermissibleReserveAircraftCount;
//
//private:
//	static std::shared_ptr<CCommonInputData> ms_Instance;
//
//
//public:
//	~CCommonInputData() {};
//
//private:
//	CCommonInputData();
//
//	CCommonInputData(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments, vector<int>& permittedMoments,
//		const CInterval& ms_SpareArrivalTimeInterval, const map<int, int>& ms_PermissibleReserveAircraftCount);
//	
//
//public:
//	static std::shared_ptr<CCommonInputData> GetInstance();
//
//	static std::shared_ptr<CCommonInputData> GetInstance(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments, vector<int>& permittedMoments,
//		const CInterval& ms_SpareArrivalTimeInterval, const map<int, int>& ms_PermissibleReserveAircraftCount);
//};

