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
	static int m_RunwayCount;

	static int m_SpecialPlaceCount;

	static CInputTakingOffMoments m_InputTakingOffMoments;

	static CInterval m_SpareArrivalTimeInterval;

	static map<int, int> m_PermissibleReserveAircraftCount;


public:
	~CCommonInputData();

private:
	CCommonInputData(int runwayCount, int specialPlaceCount);
	

public:
	//static CCommonInputData& GetInstance(int runwayCount = 2, int specialPlaceCount = 2);
};

