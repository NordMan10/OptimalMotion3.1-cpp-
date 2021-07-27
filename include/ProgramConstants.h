#pragma once

/** Крaткое описание класса
 * Какие-либо константные значения, общие для всего проекта
 * File  : ProgramConstants.h
 * Author:
 *
 * Длинное описание класса
 *
 */

class ProgramConstants
{
public:
	/// <summary>
	/// Начальное значение Id для зон массового обслуживания
	/// </summary>
	static int m_StartIdValue;

public:
	~ProgramConstants();

protected:
	ProgramConstants(int startIdValue);
	

public:
	static ProgramConstants& GetInstance(int startIdValue = 1);
};

