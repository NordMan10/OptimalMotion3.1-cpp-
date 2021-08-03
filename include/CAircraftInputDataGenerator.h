#pragma once

/** ��a���� �������� ������
 * ����� ��� ��������� ������� ������ ��� ������� ��. ��������
 *
 * File  : CAircraftInputDataGenerator.h
 * Author:
 *
 * ������� �������� ������
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
	CAircraftInputDataGenerator();

public:
	CAircraftInputDataGenerator(CAircraftInputDataGenerator& from);


public:
	static std::shared_ptr<CAircraftInputDataGenerator> GetInstance();

	std::shared_ptr<CAircraftInputData> GetAircraftInputData(int plannedTakingOffMoment);

private:
	int GetAircraftPriority();

	bool GetProcessingNecessity();

	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetTakingOffAircraftCreationIntervals();
};

