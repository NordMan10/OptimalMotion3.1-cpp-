#pragma once
/** Крaткое описание класса.
 *
 *
 * File  : CSpecialPlace.h
 * Author: Yury Ten.
 *
 * Длинное описание класса
 *
 */
#include <map>

 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CInterval.h"
#include "IMassServiceZone.h"

class CSpecialPlace : public IMassServiceZone
{
private:
	int m_Id = 0;

	/**
	 * Список интервалов занимания ПРДВ (время, когда ПРДВ занят ВС).
	 */
	std::map<int, CInterval> m_ProcessingIntervals = std::map<int, CInterval>();


public:
	CSpecialPlace(int id);


public:
	int GetId() const;

	/**
	 * Добавляет переданный интервал в список интервалов зоны, если он не пересекается с существующими интервалами.
	 * Подразумевается, что был передан свободный (не пересекающийся интервал), который был возвращен методом GetFreeInterval().
	 *
	 * \param aircraftId Id ВС.
	 * \param freeInterval Рассчитанный свободный интервал.
	 */
	void AddAircraftInterval(int aircraftId, CInterval& freeInterval);

	/**
	 * Проверяет, можно ли добавить переданный интервал в список уже существующих интервалов зоны без пересечений с ними.
	 * Если можно, то возвращает копию переданного интервала. Если нельзя, то рассчитывает новый, непересекающийся интервал.
	 *
	 * \param newInterval Интервал, который нужно проверить.
	 * \return Свободный, непересекающийся с существующими интервалами зоны, интервал.
	 */
	std::shared_ptr<CInterval> GetFreeInterval(CInterval& newInterval);

	/**
	 * Удаляет из списка интервалов занимания зоны интервал, принадлежащий ВС, Id которого был передан.
	 *
	 * \param aircraftId Id ВС, интервал которого нужно удалить.
	 */
	void RemoveAircraftInterval(int aircraftId);

	/**
	 * Очищает список интервалов занимания зоны.
	 *
	 */
	void Reset();
};