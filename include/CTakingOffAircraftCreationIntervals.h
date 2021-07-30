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
public:
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
		int motionFromSPToPS, int processing, int takeoff);

	CTakingOffAircraftCreationIntervals() = default;


public:
	int GetMotionFromParkingToPS() const;

	int GetMotionFromPSToES() const;

	int GetMotionFromParkingToSP() const;

	int GetMotionFromSPToPS() const;

	int GetProcessing() const;

	int GetTakingOff() const;

};

