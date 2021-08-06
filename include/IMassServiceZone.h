#pragma once

/**  рaткое описание класса
 *
 * File  : IMassServiceZone.h
 * Author:
 *
 * ƒлинное описание класса
 *
 */
 // SYSTEM INCLUDES
 //
#include <memory>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
# include "CInterval.h"


class IMassServiceZone
{
	/**
	 * ѕровер€ет, можно ли добавить переданный интервал в список уже существующих интервалов зоны без пересечений с ними.
	 * ≈сли можно, то возвращает копию переданного интервала. ≈сли нельз€, то рассчитывает новый, непересекающийс€ интервал.
	 *
	 * \param newInterval »нтервал, который нужно проверить.
	 * \return —вободный, непересекающийс€ с существующими интервалами зоны, интервал.
	 */
    virtual std::shared_ptr<CInterval> GetFreeInterval(CInterval& newInterval) = 0;

	/**
	 * ƒобавл€ет переданный интервал в список интервалов зоны, если он не пересекаетс€ с существующими интервалами.
	 * ѕодразумеваетс€, что был передан свободный (не пересекающийс€ интервал), который был возвращен методом GetFreeInterval().
	 *
	 * \param aircraftId Id ¬—.
	 * \param freeInterval –ассчитанный свободный интервал.
	 */
    virtual void AddAircraftInterval(int aircraftId, CInterval& freeInterval) = 0;

	/**
	 * ”дал€ет из списка интервалов занимани€ зоны интервал, принадлежащий ¬—, Id которого был передан.
	 *
	 * \param aircraftId Id ¬—, интервал которого нужно удалить.
	 */
    virtual void RemoveAircraftInterval(int aircraftId) = 0;

	/**
	 * ќчищает список интервалов занимани€ зоны.
	 *
	 */
    virtual void Reset() = 0;
};

