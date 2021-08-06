#pragma once

/** Крaткое описание класса
 * Набоор моментов, получаемых во входных данных для взлетающего ВС.
 *
 * File  : TakingOffAircraftCreationMoments.h
 * Author: Yury Ten.
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCreationMoments
{
private:
	/**
	 * Плановый момент вылета.
	 */
	int m_PlannedTakingOff = 0;


public:
	CTakingOffAircraftCreationMoments(int plannedTakingOff) { m_PlannedTakingOff = plannedTakingOff; }
	CTakingOffAircraftCreationMoments() = default;


public:
	int GetPlannedTakingOff() const { return m_PlannedTakingOff; }
};

