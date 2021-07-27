#include "../include/CCommonInputData.h"
#include <limits>

CCommonInputData::CCommonInputData(int runwayCount = 2, int specialPlaceCount = 2) : m_RunwayCount(runwayCount), m_SpecialPlaceCount(specialPlaceCount)
{
	vector<int> plannedMoments{ 600, 630, 680, 700, 750, 1040, 1290, 1310, 1500, 1580 };
	vector<int> permittedMoments{ 600, 630, 680, 700, 750, 1040, 1290, 1310, 1500, 1580 };

	m_InputTakingOffMoments = CInputTakingOffMoments(plannedMoments, permittedMoments);

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

CCommonInputData* CCommonInputData::GetInstance()
{
	if (m_pInstance == 0)
	{
		m_pInstance = new CCommonInputData();
	}

	return m_pInstance;
}

CCommonInputData* CCommonInputData::GetInstance(int runwayCount, int specialPlaceCount)
{
	if (m_pInstance == 0)
	{
		m_pInstance = new CCommonInputData(runwayCount, specialPlaceCount);
	}

	return m_pInstance;
}

