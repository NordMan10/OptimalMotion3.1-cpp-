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
private:
	CCommonInputData* m_CommonInputData;
	CProgramConstants* m_ProgramConstants;


private:
	CAircraftInputDataGenerator();



public:
	CAircraftInputDataGenerator& GetInstance();

	CAircraftInputData* GetAircraftInputData(int plannedTakingOffMoment);

private:
	int GetAircraftPriority();

	bool GetProcessingNecessity();

	CTakingOffAircraftCreationIntervals* GetTakingOffAircraftCreationIntervals();
};

