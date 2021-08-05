#pragma once

/** ��a���� �������� ������
 * ����� ��� ��������� ������� ������ ��� ������� ��. ��������
 *
 * File  : CAircraftInputDataGenerator.h
 * Author:
 *
 * ������� �������� ������
 * ���������� ������� ������ ��� ����������� ��, ��������� ������� ��������� ������ �� ������� CProgramConstants, CCommonInputData,
 * � ����� ������, ���������� �������� � �������.
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
	 * ���������� ����� �������� ������ ��� �� � ��������� �������� ��������.
	 * 
	 * \param plannedTakingOffMoment
	 * \return ��������� shared_ptr �� ��������� ������ CAircraftInputData
	 */
	std::shared_ptr<CAircraftInputData> GetAircraftInputData(int plannedTakingOffMoment);

private:
	/**
	 * ���������� �������� ��������� ��� �� � ������������� ��������������.
	 * 
	 * \return �������� ���������� ���� int
	 */
	int GetAircraftPriority();

	/**
	 * ���������� ���� ������������� ���������, ������������ ��������� �������.
	 * 
	 * \return �������� ���� bool, ������������ ������������� ���������
	 */
	bool GetProcessingNecessity();

	/**
	 * ���������� ��������� ������ �������� ���������� ��� �� (�����, ���� ������ ��� ������� �� �� ����� ������������ ��������). 
	 * �������� ���������� �������� � ��������� ��������� �� �������� ��������.
	 * 
	 * \return ��������� shared_ptr �� ��������� ������ CTakingOffAircraftCreationIntervals
	 */
	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetTakingOffAircraftCreationIntervals();
};

