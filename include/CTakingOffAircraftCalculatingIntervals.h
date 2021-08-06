#pragma once

/** Крaткое описание класса
 * Набор рассчитываемых интервалов для взлетающего ВС
 * 
 * File  : TakingOffAircraftCalculatingIntervals.h
 * Author: Yury Ten
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCalculatingIntervals
{
private:
	/**
	 * Время апростоя на ПРДВ.
	 */
	int m_PSDelay = 0;


public:
	CTakingOffAircraftCalculatingIntervals() {};


public:
	int GetPSDelay() const { return m_PSDelay; }

	void SetPSDelay(int PSDelay) { m_PSDelay = PSDelay; }
};

