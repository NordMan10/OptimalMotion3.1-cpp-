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
	static int ms_StartIdValue;

public:
	~CProgramConstants();

private:
	CProgramConstants(int startIdValue);
	

public:
	static CProgramConstants& GetInstance(int startIdValue = 1);
};

