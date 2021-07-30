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
	static int m_RunwayCount;

	static int m_SpecialPlaceCount;

	static CInputTakingOffMoments m_InputTakingOffMoments;

	static CInterval m_SpareArrivalTimeInterval;

	static std::map<int, int> m_PermissibleReserveAircraftCount;

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
//	static int m_RunwayCount;
//
//	static int m_SpecialPlaceCount;
//
//	static std::shared_ptr<CInputTakingOffMoments> m_InputTakingOffMoments;
//
//	CInterval m_SpareArrivalTimeInterval;
//
//	map<int, int> m_PermissibleReserveAircraftCount;
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
//		const CInterval& m_SpareArrivalTimeInterval, const map<int, int>& m_PermissibleReserveAircraftCount);
//	
//
//public:
//	static std::shared_ptr<CCommonInputData> GetInstance();
//
//	static std::shared_ptr<CCommonInputData> GetInstance(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments, vector<int>& permittedMoments,
//		const CInterval& m_SpareArrivalTimeInterval, const map<int, int>& m_PermissibleReserveAircraftCount);
//};

