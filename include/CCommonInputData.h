#pragma once

/** Крaткое описание класса
 * Класс для входящих данных, общих для всей программы
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
#include <memory>


class CCommonInputData final
{
private:
	/**
	 * Количество ВПП.
	 */
	static int ms_RunwayCount;

	/**
	 * Количество спец. площадок.
	 */
	static int ms_SpecialPlaceCount;

	/**
	 * Наборы разрешенных и плановых моментов для инициализации класса CInputTakingOffMoments.
	 */
	static std::vector<int> ms_PlannedMoments;
	static std::vector<int> ms_PermittedMoments;

	/**
	 * Класс с наборами плановых и разрешенных моментов и методами работы с ними
	 */
	static CInputTakingOffMoments ms_InputTakingOffMoments;

	/**
	 * Интервал запасного времени прибытия.
	 */
	static CInterval ms_SpareArrivalTimeInterval;

	/**
	 * Допустимое количество резервных ВС в зависимости от времени простоя.
	 */
	static std::map<int, int> ms_PermissibleReserveAircraftCount;

	
public:
	static int GetRunwayCount();
	static void SetRunwayCount(int value);

	static int GetSpecialPlaceCount();
	static void SetSpecialPlaceCount(int value);

	static CInputTakingOffMoments& GetInputTakingOffMoments();

	static CInterval& GetSpareArrivalTimeInterval();
	static void SetSpareArrivalTimeInterval(CInterval& value);

	static std::map<int, int>& GetPermissibleReserveAircraftCount();
};
