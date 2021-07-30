#pragma once

/** Крaткое описание класса
 * Класс для генерации уникальных Id для ВС. Синглтон
 * File  : CAircraftIDGenerator.h
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


class CAircraftIDGenerator
{
private:
	int m_InitIdValue;
	int m_Id;
	static std::shared_ptr<CAircraftIDGenerator> m_Instance;


public:
	~CAircraftIDGenerator() {};

private:
	CAircraftIDGenerator(int id);


public:
	static std::shared_ptr<CAircraftIDGenerator> GetInstance(int initIdValue);

	/// <summary>
	/// Возвращает уникальный Id для ВС
	/// </summary>
	/// <returns></returns>
	int GetUniqueAircraftId();

	/// <summary>
	/// Сбрасывает значение Id до значения, переданного при создании
	/// </summary>
	void Reset();

};

