#pragma once

/** Крaткое описание класса
 * Набор интервалов, получаемых во входных данных для взлетающего ВС
 *
 * File  : TakingOffAircraftCreationIntervals.h
 * Author: Yury Ten.
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCreationIntervals
{
private:
	/**
	 * Время руления от парковки до ПРДВ.
	 */
	int m_MotionFromParkingToPS;

	/**
	 * Время руления от ПРДВ до ИСП.
	 */
	int m_MotionFromPSToES;

	/**
	 * Время руления от парковки до Спец. площадки.
	 */
	int m_MotionFromParkingToSP;

	/**
	 * Время руления от Спец. площадки до ПРДВ.
	 */
	int m_MotionFromSPToPS;

	/**
	 * Время обработки.
	 */
	int m_Processing;

	/**
	 * Время взлета.
	 */
	int m_TakingOff;


public:
	CTakingOffAircraftCreationIntervals(
		int motionFromParkingToPS, int motionFromPSToES, int motionFromParkingToSP,
		int motionFromSPToPS, int processing, int takingOff);

	CTakingOffAircraftCreationIntervals() = default;


public:
	int GetMotionFromParkingToPS() const { return m_MotionFromParkingToPS; }

	int GetMotionFromPSToES() const { return m_MotionFromPSToES; }

	int GetMotionFromParkingToSP() const { return m_MotionFromParkingToSP; }

	int GetMotionFromSPToPS() const { return m_MotionFromSPToPS; }

	int GetProcessing() const { return m_Processing; }

	int GetTakingOff() const { return m_TakingOff; }

};

