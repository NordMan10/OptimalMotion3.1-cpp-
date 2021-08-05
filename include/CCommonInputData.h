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
#include <memory>


class CCommonInputData final
{
private:
	static int ms_RunwayCount;

	static int ms_SpecialPlaceCount;

	static CInputTakingOffMoments ms_InputTakingOffMoments;

	static CInterval ms_SpareArrivalTimeInterval;

	static std::map<int, int> ms_PermissibleReserveAircraftCount;

	/// <summary>
	/// Количество ВПП
	/// </summary>
public:
	static int GetRunwayCount();
	static void SetRunwayCount(int value);

	/// <summary>
	/// Количество спец. площадок
	/// </summary>
	static int GetSpecialPlaceCount();
	static void SetSpecialPlaceCount(int value);

	/// <summary>
	/// Наборы плановых и разрешенных моментов
	/// </summary>
	static CInputTakingOffMoments& GetInputTakingOffMoments();

	/// <summary>
	///  Интервал запасного времени прибытия
	/// </summary>
	static CInterval& GetSpareArrivalTimeInterval();
	static void SetSpareArrivalTimeInterval(CInterval& value);

	/// <summary>
	/// Допустимое количество резервных ВС в зависимости от времени простоя
	/// </summary>
	static std::map<int, int>& GetPermissibleReserveAircraftCount();
};
