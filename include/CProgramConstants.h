#pragma once

/** Крaткое описание класса
 * Какие-либо константные значения, общие для всей программы
 * File  : ProgramConstants.h
 * Author: Yury Ten
 *
 * Длинное описание класса
 *
 */

// SYSTEM INCLUDES
//

// PROJECT INCLUDES
//

// LOCAL INCLUDES
//


class CProgramConstants
{
public:
	/**
	 * Начальное значение Id для зон массового обслуживания.
	 */
	static int ms_StartIdValue;

	/**
	 * Время руления от парковки до ПРДВ.
	 */
	static int ms_MotionFromParkingToPS;

	/**
	 * Время руления от ПРДВ до ИСП.
	 */
	static int ms_MotionFromPSToES;

	/**
	 * Время руления от парковки до Спец. площадки.
	 */
	static int ms_MotionFromParkingToSP;

	/**
	 * Время руления от Спец. площадки до ПРДВ.
	 */
	static int ms_MotionFromSPToPS;

	/**
	 * Время взлета.
	 */
	static int ms_TakingOffInterval;

	/**
	 * Время обработки.
	 */
	static int ms_ProcessingTime;

};