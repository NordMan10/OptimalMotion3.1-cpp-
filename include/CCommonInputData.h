#pragma once

/** Крaткое описание класса
 * Класс для общих входных данных
 * File  : CCommonInputData.h
 * Author: Yury Ten
 *
 * Длинное описание класса
 *
 */

 // SYSTEM INCLUDES
#include <map>

// LOCAL INCLUDES
#include "./CInputTakingOffMoments.h"
#include "CInterval.h"


class CCommonInputData
{
public:
	int m_RunwayCount;

	int m_SpecialPlaceCount;

	CInputTakingOffMoments* m_InputTakingOffMoments;

	CInterval m_SpareArrivalTimeInterval;

	map<int, int> m_PermissibleReserveAircraftCount;

private:
	static CCommonInputData* ms_Instance;


public:
	~CCommonInputData();

private:
	CCommonInputData();

	CCommonInputData(int runwayCount, int specialPlaceCount);

	CCommonInputData(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments, vector<int>& permittedMoments,
		const CInterval& m_SpareArrivalTimeInterval, const map<int, int>& m_PermissibleReserveAircraftCount);
	

public:
	static CCommonInputData* GetInstance();

	static CCommonInputData* GetInstance(int runwayCount, int specialPlaceCount);

	static CCommonInputData& GetInstance(int runwayCount, int specialPlaceCount, vector<int>& plannedMoments, vector<int>& permittedMoments,
		const CInterval& m_SpareArrivalTimeInterval, const map<int, int>& m_PermissibleReserveAircraftCount);
};

