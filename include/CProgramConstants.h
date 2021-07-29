#pragma once

/** Крaткое описание класса
 * Какие-либо константные значения, общие для всего проекта
 * File  : ProgramConstants.h
 * Author:
 *
 * Длинное описание класса
 *
 */

class CProgramConstants
{
public:
	/// <summary>
	/// Начальное значение Id для зон массового обслуживания
	/// </summary>
	int m_StartIdValue = 1;

	/// <summary>
	/// Время руления от парковки до ПРДВ
	/// </summary>
	int m_MotionFromParkingToPS = 240;

	/// <summary>
	/// Время руления от ПРДВ до ИСП
	/// </summary>
	int m_MotionFromPSToES = 40;

	/// <summary>
	/// Время руления от парковки до Спец. площадки
	/// </summary>
	int m_MotionFromParkingToSP = 120;

	/// <summary>
	/// Время руления от Спец. площадки до ПРДВ
	/// </summary>
	int m_MotionFromSPToPS = 120;

	/// <summary>
	/// Время взлета
	/// </summary>
	int m_TakingOffInterval = 30;

	/// <summary>
	/// Время обработки
	/// </summary>
	int m_ProcessingTime = 240;
	
private:
	static CProgramConstants* m_Instance;


public:
	~CProgramConstants();

private:
	CProgramConstants();
	

public:
	static CProgramConstants* GetInstance();
};

