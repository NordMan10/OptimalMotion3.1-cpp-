#pragma once

/** Крaткое описание класса
 * Класс для генерации уникальных Id для ВС. Синглтон
 * File  : AircraftIdGenerator.h
 * Author:
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


class AircraftIdGenerator
{
private:
	int m_InitIdValue;
	int m_Id;

public:
	~AircraftIdGenerator();

	static AircraftIdGenerator* GetInstance(int initIdValue);

	/// <summary>
	/// Возвращает уникальный Id для ВС
	/// </summary>
	/// <returns></returns>
	int GetUniqueAircraftId();

	/// <summary>
	/// Сбрасывает значение Id до значения, переданного при создании
	/// </summary>
	void Reset();

private:
	AircraftIdGenerator(int id);
};

