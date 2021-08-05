#pragma once

/** Крaткое описание класса
 * Класс, содержащий реализацию общих методов для интерфейса IMassServiceZone
 * 
 * File  : CIMassServiceZoneExtensions.h
 * Author:
 *
 * Длинное описание класса
 * Класс, содержащий реализацию общих методов для интерфейса зоны массового обслуживания (IMassServiceZone).
   Описание данного интерфейса см. в определении интерфейса IMassServiceZone
 */
 // SYSTEM INCLUDES
 //	
#include <map>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "IMassServiceZone.h"
#include "CInterval.h"


class CIMassServiceZoneExtensions
{
public:
	/**
	 * Добавляет переданный интервал в список интервалов зоны, если он не пересекается с существующими интервалами. Подразумевает, что
	   был передан свободный (не пересекающийся) интервал.
	 * 
	 * \param zone Зона массового обслуживания IMassServiceZone
	 * \param aircraftId Id ВС
	 * \param freeInterval Рассчитанный свободный интервал
	 * \param zoneIntervals Набор существующих интервалов
	 */
	static void AddAircraftInterval(IMassServiceZone* zone, int aircraftId, const CInterval& freeInterval, std::map<int, CInterval>& zoneIntervals);

	/**
	 * Возвращает свободный (непересекающийся с существующими интервалами) интервал.
	 * 
	 * \param zone Зона массового обслуживания
	 * \param interval Интервал, который нужно проверить
	 * \param zoneIntervals Набор существующих интервалов
	 * \return Указатель shared_ptr на экземпляр класса CInterval
	 */
	static std::shared_ptr<CInterval> GetFreeInterval(IMassServiceZone* zone, const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);

	/**
	 * Удаляет интервал из набора существующих интервалов по Id ВС.
	 * 
	 * \param zone Зона массового обслуживания
	 * \param aircraftId Id ВС
	 * \param zoneIntervals Набор существующих интервалов
	 */
	static void RemoveAircraftInterval(IMassServiceZone* zone, int aircraftId, std::map<int, CInterval>& zoneIntervals);

private:
	/**
	 * Проверяет пересечение переданного интервала с набором существующих интервалов.
	 * 
	 * \param interval Интервал для проверки
	 * \param zoneIntervals Набор существующих интервалов
	 * \return Значение bool, определяющее наличие пересечения
	 */
	static bool CheckIntervalsIntersection(const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);
};

