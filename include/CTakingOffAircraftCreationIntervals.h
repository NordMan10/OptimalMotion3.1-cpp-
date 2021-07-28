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
	/// Время взлета
	/// </summary>
	int m_TakingOff;

	/// <summary>
	/// Время обработки
	/// </summary>
	int m_Processing;


public:
	CTakingOffAircraftCreationIntervals(
		int motionFromParkingToPS, int motionFromPSToES, int takeoff,
		int motionFromParkingToSP, int motionFromSPToPS, int processing);

	CTakingOffAircraftCreationIntervals() = default;
};

