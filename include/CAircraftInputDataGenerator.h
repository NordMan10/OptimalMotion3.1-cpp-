#pragma once

/** ��a���� �������� ������
 * ����� ��� ��������� ������� ������ ��� ������� ��. ��������
 *
 * File  : CAircraftInputDataGenerator.h
 * Author: Yury Ten.
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
	 * ���������� ����� �������� ������ ��� �� �� ���������� ��������� �������.
	 * 
	 * \param plannedTakingOffMoment.
	 * \return ������� ������ ��� �� � ���� ���������� ������ CAircraftInputData.
	 */
	std::shared_ptr<CAircraftInputData> GetAircraftInputData(int plannedTakingOffMoment);

private:
	/**
	 * ���������� �������� ��������� ��� �� � ������������� ��������������.
	 * 
	 * \return �������� ���������� � ���� int.
	 */
	int GetAircraftPriority();

	/**
	 * ���������� ������� ������������� ���������, ������������ ��������� �������.
	 * 
	 * \return �������� bool, ������������ ������������� ���������.
	 */
	bool GetProcessingNecessity();

	/**
	 * ������� ����� ���������� ��� �� � ���� ���������� ������ CTakingOffAircraftCreationIntervals 
	 * (�����, ���� ������ ��� ������� �� �� ����� ������������ ������ ��������). 
	 * �������� ���������� �������� � ��������� ��������� �� �������� ��������.
	 * 
	 * \return ����� ���������� ��� ��.
	 */
	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetTakingOffAircraftCreationIntervals();
};

