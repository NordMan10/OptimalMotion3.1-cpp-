#pragma once
/** Крaткое описание класса
 * Представление ВПП
 *
 * File  : CRunway.h
 * Author: Yury Ten
 *
 * Длинное описание класса
 *
 */

 // SYSTEM INCLUDES
 //
#include <map>
#include <string>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CInterval.h"
#include "IMassServiceZone.h"


class CRunway : public IMassServiceZone
{
private:
	std::string m_Id;

	/**
	 * Список интервалов занимания ВПП (время, когда ВПП занята ВС).
	 */
	std::map<int, CInterval> m_OccupiedIntervals = std::map<int, CInterval>();
	 

public:
	CRunway(std::string id);


public:
	std::string GetId() const;

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

