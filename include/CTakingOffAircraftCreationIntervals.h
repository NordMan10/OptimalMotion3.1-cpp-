#pragma once

/** Крaткое описание класса
 * Интерваоы, получаемые во входных данных для взлетающего ВС
 *
 * File  : TakingOffAircraftCreationIntervals.h
 * Author:
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCreationIntervals
{
private:
	/// <summary>
	/// Время руления от парковки до ПРДВ
	/// </summary>
	int m_MotionFromParkingToPS;

	/// <summary>
	/// Время руления от ПРДВ до ИСП
	/// </summary>
	int m_MotionFromPSToES;

	/// <summary>
	/// Время руления от парковки до Спец. площадки
	/// </summary>
	int m_MotionFromParkingToSP;

	/// <summary>
	/// Время руления от Спец. площадки до ПРДВ
	/// </summary>
	int m_MotionFromSPToPS;

	/// <summary>
	/// Время обработки
	/// </summary>
	int m_Processing;

	/// <summary>
	/// Время взлета
	/// </summary>
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

