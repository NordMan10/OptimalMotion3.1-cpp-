#pragma once

/** Крaткое описание класса
 * Рассчитываемые интервалы для взлетающего ВС
 * File  : TakingOffAircraftCalculatingIntervals.h
 * Author:
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCalculatingIntervals
{
private:
	int m_PSDelay = 0;


public:
	CTakingOffAircraftCalculatingIntervals() {};


public:
	int GetPSDelay() const { return m_PSDelay; }

	void SetPSDelay(int PSDelay) { m_PSDelay = PSDelay; }
};

