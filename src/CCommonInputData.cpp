#include "../include/CCommonInputData.h"
#include <limits>

CCommonInputData::CCommonInputData()
{
	m_RunwayCount = 2;
	m_SpecialPlaceCount = 2;

	vector<int> plannedMoments{ 600, 630, 680, 700, 750, 1040, 1290, 1310, 1500, 1580 };
	vector<int> permittedMoments
	{
		660, 750, 790, 850, 880, 940, 1060, 1120, 1200, 1280, 1670,
		1700, 1760, 1800, 1900, 2000, 2090, 2150, 2240, 2390, 2500
	};

	m_InputTakingOffMoments = std::shared_ptr<CInputTakingOffMoments>(new CInputTakingOffMoments(plannedMoments, permittedMoments));

	m_SpareArrivalTimeInterval = CInterval(20, 50);

	m_PermissibleReserveAircraftCount = map<int, int>
	{
		{ 0, numeric_limits<int>::max() },
		{ 1, 300 },
		{ 2, 240 },
		{ 3, 180 },
		{ 4, 120 },
		{ 5, 10 },
		{ numeric_limits<int>::max(), 0 }
	};
}

CCommonInputData::CCommonInputData(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments, vector<int>& permittedMoments,
	const CInterval& spareArrivalTimeInterval, const map<int, int>& permissibleReserveAircraftCount)
{
	m_RunwayCount = runwayCount;
	m_SpecialPlaceCount = specialPlaceCount;

	m_InputTakingOffMoments = std::shared_ptr<CInputTakingOffMoments>(new CInputTakingOffMoments(plannedMoments, permittedMoments));

	m_SpareArrivalTimeInterval = CInterval(spareArrivalTimeInterval);

	m_PermissibleReserveAircraftCount = map<int, int>(permissibleReserveAircraftCount);
}

std::shared_ptr<CCommonInputData> CCommonInputData::GetInstance()
{
	if (!ms_Instance)
		CCommonInputData* ms_Instance = new CCommonInputData();

	return ms_Instance;
}

std::shared_ptr<CCommonInputData> CCommonInputData::ms_Instance = nullptr;

std::shared_ptr<CCommonInputData> CCommonInputData::GetInstance(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments,
	vector<int>& permittedMoments, const CInterval& spareArrivalTimeInterval, const map<int, int>& permissibleReserveAircraftCount)
{
	if (!ms_Instance)
		auto ms_Instance = std::shared_ptr<CCommonInputData>(new CCommonInputData(runwayCount, specialPlaceCount, plannedMoments,
			permittedMoments, spareArrivalTimeInterval, permissibleReserveAircraftCount));

	return ms_Instance;
}
