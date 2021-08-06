#pragma once

/** Крaткое описание класса
 * Класс для генерации входных данных для каждого ВС. Синглтон
 *
 * File  : CAircraftInputDataGenerator.h
 * Author: Yury Ten.
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
	 * Составляет набор входящих данных для ВС по указанному плановыму моменту.
	 * 
	 * \param plannedTakingOffMoment.
	 * \return Входные данные для ВС в виде экземпляра класса CAircraftInputData.
	 */
	std::shared_ptr<CAircraftInputData> GetAircraftInputData(int plannedTakingOffMoment);

private:
	/**
	 * Определяет значение приритета для ВС с неравномерным распределением.
	 * 
	 * \return Значение приоритета в виде int.
	 */
	int GetAircraftPriority();

	/**
	 * Определяет признак необходимости обработки, генерируемый случайным образом.
	 * 
	 * \return Значение bool, определяющее необходимость обработки.
	 */
	bool GetProcessingNecessity();

	/**
	 * Создает набор интервалов для ВС в виде экземпляра класса CTakingOffAircraftCreationIntervals 
	 * (нужен, пока данные для каждого ВС не будут передаваться другим способом). 
	 * Значения интервалов задаются с некоторым разбросом от среднего значения.
	 * 
	 * \return Набор интервалов для ВС.
	 */
	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetTakingOffAircraftCreationIntervals();
};

