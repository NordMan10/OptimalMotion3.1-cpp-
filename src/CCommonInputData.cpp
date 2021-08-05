#include "../include/CCommonInputData.h"
#include <limits>


int CCommonInputData::ms_RunwayCount = 2;

int CCommonInputData::ms_SpecialPlaceCount = 2;


std::vector<int> CCommonInputData::ms_PlannedMoments = std::vector<int>{ 600, 630, 680, 700, 750, 1040, 1290, 1310, 1500, 1580 };

std::vector<int> CCommonInputData::ms_PermittedMoments = std::vector<int>
	{ 660, 750, 790, 850, 880, 940, 1060, 1120, 1200, 1280, 1670, 
	1700, 1760, 1800, 1900, 2000, 2090, 2150, 2240, 2390, 2500 };


CInputTakingOffMoments CCommonInputData::ms_InputTakingOffMoments = CInputTakingOffMoments{ ms_PlannedMoments, ms_PermittedMoments };

CInterval CCommonInputData::ms_SpareArrivalTimeInterval = CInterval(20, 50);

std::map<int, int> CCommonInputData::ms_PermissibleReserveAircraftCount =
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
	return ms_RunwayCount;
}

void CCommonInputData::SetRunwayCount(int value)
{
	ms_RunwayCount = value;
}

int CCommonInputData::GetSpecialPlaceCount()
{
	return ms_SpecialPlaceCount;
}

void CCommonInputData::SetSpecialPlaceCount(int value)
{
	ms_SpecialPlaceCount = value;
}

CInputTakingOffMoments& CCommonInputData::GetInputTakingOffMoments()
{
	return ms_InputTakingOffMoments;
}

CInterval& CCommonInputData::GetSpareArrivalTimeInterval()
{
	return ms_SpareArrivalTimeInterval;
}

void CCommonInputData::SetSpareArrivalTimeInterval(CInterval& interval)
{
	ms_SpareArrivalTimeInterval = CInterval(interval);
}

std::map<int, int>& CCommonInputData::GetPermissibleReserveAircraftCount()
{
	return ms_PermissibleReserveAircraftCount;
}
