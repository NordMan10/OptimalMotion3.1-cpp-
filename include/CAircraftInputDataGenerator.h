#pragma once

/** Крaткое описание класса
 * Класс для генерации входных данных для каждого ВС. Синглтон
 *
 * File  : CAircraftInputDataGenerator.h
 * Author:
 *
 * Длинное описание класса
 * Генерирует входные данные для конкретного ВС, используя заранее созданные данные из классов CProgramConstants, CCommonInputData,
 * а также данные, прописаные напрямую в методах.
 */

 // SYSTEM INCLUDES
 //
#include <random>
#include "CAircraftInputData.h"

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CAircraftInputDataGenerator
{
public:
	static std::shared_ptr<CAircraftInputDataGenerator> m_Instance;


private:
	CAircraftInputDataGenerator();
	CAircraftInputDataGenerator(CAircraftInputDataGenerator& from);


public:
	static std::shared_ptr<CAircraftInputDataGenerator> GetInstance();

	/**
	 * Возвращает набор входящих данных для ВС с кокретным плановым моментом.
	 * 
	 * \param plannedTakingOffMoment
	 * \return Указатель shared_ptr на экземпляр класса CAircraftInputData
	 */
	std::shared_ptr<CAircraftInputData> GetAircraftInputData(int plannedTakingOffMoment);

private:
	/**
	 * Возвращает значение приритета для ВС с неравномерным распределением.
	 * 
	 * \return Значение приоритета типа int
	 */
	int GetAircraftPriority();

	/**
	 * Возвращает флаг необходимости обработки, генерируемый случайным образом.
	 * 
	 * \return Значение типа bool, определяющее необходимость обработки
	 */
	bool GetProcessingNecessity();

	/**
	 * Возвращает экземпляр класса заданных интервалов для ВС (нужен, пока данные для каждого ВС не будут передаваться напрямую). 
	 * Значения интервалов задаются с некоторым разбросом от среднего значения.
	 * 
	 * \return Указатель shared_ptr на экземпляр класса CTakingOffAircraftCreationIntervals
	 */
	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetTakingOffAircraftCreationIntervals();
};

