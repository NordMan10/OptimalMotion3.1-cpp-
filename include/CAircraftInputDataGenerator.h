#pragma once

/** Крaткое описание класса
 * Класс для генерации входных данных для каждого ВС. Синглтон
 *
 * File  : CAircraftInputDataGenerator.h
 * Author:
 *
 * Длинное описание класса
 *
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
	std::shared_ptr<CCommonInputData> m_CommonInputData;
	std::shared_ptr<CProgramConstants> m_ProgramConstants;


private:
	CAircraftInputDataGenerator();



public:
	static std::shared_ptr<CAircraftInputDataGenerator> GetInstance();

	std::shared_ptr<CAircraftInputData> GetAircraftInputData(int plannedTakingOffMoment);

private:
	int GetAircraftPriority();

	bool GetProcessingNecessity();

	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetTakingOffAircraftCreationIntervals();
};

