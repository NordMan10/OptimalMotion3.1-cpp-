#include "../include/CCommonInputData.h"
#include <limits>

CCommonInputData::CCommonInputData(int runwayCount, int specialPlaceCount)
{
	m_RunwayCount = runwayCount;
	m_SpecialPlaceCount = specialPlaceCount;

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

//CCommonInputData& CCommonInputData::GetInstance(int runwayCount = 2, int specialPlaceCount = 2)
//{
//	static CCommonInputData instance{ runwayCount, specialPlaceCount };
//
//	return instance;
//}

