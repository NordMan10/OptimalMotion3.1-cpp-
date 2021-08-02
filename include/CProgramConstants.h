#pragma once
#include <memory>

/** Крaткое описание класса
 * Какие-либо константные значения, общие для всего проекта
 * File  : ProgramConstants.h
 * Author:
 *
 * Длинное описание класса
 *
 */

// SYSTEM INCLUDES
//
#include <memory>

// PROJECT INCLUDES
//

// LOCAL INCLUDES
//


class CProgramConstants
{
public:
	/// <summary>
	/// Начальное значение Id для зон массового обслуживания
	/// </summary>
	static int ms_StartIdValue;

	/// <summary>
	/// Время руления от парковки до ПРДВ
	/// </summary>
	static int ms_MotionFromParkingToPS;

	/// <summary>
	/// Время руления от ПРДВ до ИСП
	/// </summary>
	static int ms_MotionFromPSToES;

	/// <summary>
	/// Время руления от парковки до Спец. площадки
	/// </summary>
	static int ms_MotionFromParkingToSP;

	/// <summary>
	/// Время руления от Спец. площадки до ПРДВ
	/// </summary>
	static int ms_MotionFromSPToPS;

	/// <summary>
	/// Время взлета
	/// </summary>
	static int ms_TakingOffInterval;

	/// <summary>
	/// Время обработки
	/// </summary>
	static int ms_ProcessingTime;

};