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

	CInputTakingOffMoments m_InputTakingOffMoments;

	CInterval m_SpareArrivalTimeInterval;

	map<int, int> m_PermissibleReserveAircraftCount;


public:
	~CCommonInputData();

protected:
	CCommonInputData(int runwayCount, int specialPlaceCount);
	

public:
	static CCommonInputData& GetInstance(int runwayCount = 2, int specialPlaceCount = 2);
};

