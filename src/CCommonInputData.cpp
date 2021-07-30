#include "../include/CCommonInputData.h"
#include <limits>


int CCommonInputData::m_RunwayCount = 2;

int CCommonInputData::m_SpecialPlaceCount = 2;



CInputTakingOffMoments CCommonInputData::m_InputTakingOffMoments = CInputTakingOffMoments{ std::vector<int> { 600, 630, 680, 700, 750, 1040, 1290, 1310, 1500, 1580 },
		std::vector<int> {660, 750, 790, 850, 880, 940, 1060, 1120, 1200, 1280, 1670, 1700, 1760, 1800, 1900, 2000, 2090, 2150, 2240, 2390, 2500} };

CInterval CCommonInputData::m_SpareArrivalTimeInterval = CInterval(20, 50);

std::map<int, int> CCommonInputData::m_PermissibleReserveAircraftCount =
{
	{0, std::numeric_limits<int>::max()},
	{1, 300},
	{2, 240},
	{3, 180},
	{4, 120},
	{5, 10},
	{std::numeric_limits<int>::max(), 0}
};

int CCommonInputData::GetRunwayCount()
{
	return m_RunwayCount;
}

void CCommonInputData::SetRunwayCount(int value)
{
	m_RunwayCount = value;
}

int CCommonInputData::GetSpecialPlaceCount()
{
	return m_SpecialPlaceCount;
}

void CCommonInputData::SetSpecialPlaceCount(int value)
{
	m_SpecialPlaceCount = value;
}

CInputTakingOffMoments* CCommonInputData::GetInputTakingOffMoments()
{
	return &m_InputTakingOffMoments;
}

CInterval* CCommonInputData::GetSpareArrivalTimeInterval()
{
	return &m_SpareArrivalTimeInterval;
}

void CCommonInputData::SetSpareArrivalTimeInterval(CInterval* value)
{
	m_SpareArrivalTimeInterval = *value;
}

std::map<int, int> CCommonInputData::GetPermissibleReserveAircraftCount()
{
	return m_PermissibleReserveAircraftCount;
}


//CCCommonInputData::CCCommonInputData()
//{
//	m_RunwayCount = 2;
//	m_SpecialPlaceCount = 2;
//
//	vector<int> plannedMoments{ 600, 630, 680, 700, 750, 1040, 1290, 1310, 1500, 1580 };
//	vector<int> permittedMoments
//	{
//		660, 750, 790, 850, 880, 940, 1060, 1120, 1200, 1280, 1670,
//		1700, 1760, 1800, 1900, 2000, 2090, 2150, 2240, 2390, 2500
//	};
//
//	m_InputTakingOffMoments = std::shared_ptr<CInputTakingOffMoments>(new CInputTakingOffMoments(plannedMoments, permittedMoments));
//
//	m_SpareArrivalTimeInterval = CInterval(20, 50);
//
//	m_PermissibleReserveAircraftCount = map<int, int>
//	{
//		{ 0, numeric_limits<int>::max() },
//		{ 1, 300 },
//		{ 2, 240 },
//		{ 3, 180 },
//		{ 4, 120 },
//		{ 5, 10 },
//		{ numeric_limits<int>::max(), 0 }
//	};
//}
//
//CCCommonInputData::CCCommonInputData(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments, vector<int>& permittedMoments,
//	const CInterval& spareArrivalTimeInterval, const map<int, int>& permissibleReserveAircraftCount)
//{
//	m_RunwayCount = runwayCount;
//	m_SpecialPlaceCount = specialPlaceCount;
//
//	m_InputTakingOffMoments = std::shared_ptr<CInputTakingOffMoments>(new CInputTakingOffMoments(plannedMoments, permittedMoments));
//
//	m_SpareArrivalTimeInterval = CInterval(spareArrivalTimeInterval);
//
//	m_PermissibleReserveAircraftCount = map<int, int>(permissibleReserveAircraftCount);
//}
//
//std::shared_ptr<CCCommonInputData> CCCommonInputData::GetInstance()
//{
//	if (!ms_Instance)
//		CCCommonInputData* ms_Instance = new CCCommonInputData();
//
//	return ms_Instance;
//}
//
//std::shared_ptr<CCCommonInputData> CCCommonInputData::ms_Instance = nullptr;
//
//std::shared_ptr<CCCommonInputData> CCCommonInputData::GetInstance(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments,
//	vector<int>& permittedMoments, const CInterval& spareArrivalTimeInterval, const map<int, int>& permissibleReserveAircraftCount)
//{
//	if (!ms_Instance)
//		auto ms_Instance = std::shared_ptr<CCCommonInputData>(new CCCommonInputData(runwayCount, specialPlaceCount, plannedMoments,
//			permittedMoments, spareArrivalTimeInterval, permissibleReserveAircraftCount));
//
//	return ms_Instance;
//}
