#pragma once

/**  рaткое описание класса
 *  ласс, содержащий реализацию общих методов дл€ интерфейса IMassServiceZone
 * 
 * File  : CIMassServiceZoneExtensions.h
 * Author: Yury Ten
 *
 * ƒлинное описание класса
 *  ласс, содержащий реализацию общих методов дл€ интерфейса зоны массового обслуживани€ (IMassServiceZone).
   ќписание данного интерфейса см. в определении интерфейса IMassServiceZone
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
	 * ƒобавл€ет переданный интервал в список интервалов зоны, если он не пересекаетс€ с существующими интервалами.
	 * ѕодразумеваетс€, что был передан свободный (не пересекающийс€ интервал), который был возвращен методом GetFreeInterval().
	 * 
	 * \param zone «она массового обслуживани€ IMassServiceZone
	 * \param aircraftId Id ¬—
	 * \param freeInterval –ассчитанный свободный интервал
	 * \param zoneIntervals —писок существующих интервалов зоны
	 */
	static void AddAircraftInterval(IMassServiceZone* zone, int aircraftId, const CInterval& freeInterval, std::map<int, CInterval>& zoneIntervals);

	/**
	 * ѕровер€ет, можно ли добавить переданный интервал в список уже существующих интервалов зоны без пересечений с ними.
	 * ≈сли можно, то возвращает копию переданного интервала. ≈сли нельз€, то рассчитывает новый, непересекающийс€ интервал.
	 * 
	 * \param zone «она массового обслуживани€.
	 * \param interval »нтервал, который нужно проверить.
	 * \param zoneIntervals —писок существующих интервалов зоны.
	 * \return —вободный, непересекающийс€ с существующими интервалами зоны, интервал.
	 */
	static std::shared_ptr<CInterval> GetFreeInterval(IMassServiceZone* zone, const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);

	/**
	 * ”дал€ет из списка интервалов занимани€ зоны интервал, принадлежащий ¬—, Id которого был передан.
	 * 
	 * \param zone «она массового обслуживани€.
	 * \param aircraftId Id ¬—, интервал которого нужно удалить.
	 * \param zoneIntervals —писок существующих интервалов зоны.
	 */
	static void RemoveAircraftInterval(IMassServiceZone* zone, int aircraftId, std::map<int, CInterval>& zoneIntervals);

private:
	/**
	 * ѕровер€ет пересечение переданного интервала с набором существующих интервалов.
	 * 
	 * \param interval »нтервал, который нужно проверить.
	 * \param zoneIntervals —писок существующих интервалов зоны.
	 * \return «начение bool, определ€ющее наличие пересечени€.
	 */
	static bool CheckIntervalsIntersection(const CInterval& interval, const std::map<int, CInterval>& zoneIntervals);
};

