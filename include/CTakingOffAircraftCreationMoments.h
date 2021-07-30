#pragma once

/** Крaткое описание класса
 * Моменты, получаемые во входных данных для взлетающего ВС
 *
 * File  : TakingOffAircraftCreationMoments	.h
 * Author:
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCreationMoments
{
public:
	/// <summary>
	/// Плановый момент вылета
	/// </summary>
	int m_PlannedTakingOff = 0;


public:
	CTakingOffAircraftCreationMoments(int plannedTakingOff);
	CTakingOffAircraftCreationMoments() = default;


public:
	int GetPlannedTakingOff() const;
};

