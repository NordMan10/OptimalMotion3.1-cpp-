#pragma once

/** ��a���� �������� ������
 * ����� ������� ������, ����������� ��� ������� ��
 *
 * File  : CAircraftInputData.h
 * Author:
 *
 * ������� �������� ������
 *
 */

 // SYSTEM INCLUDES
 //
#include <string>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CTakingOffAircraftCreationIntervals.h"
#include "CTakingOffAircraftCreationMoments.h"


class CAircraftInputData
{
public:
	std::string m_RunwayId;

	int m_SpecialPlaceId;

	std::string m_Type;

	int m_Priority;

	bool m_ProcessingIsNeeded;

	CTakingOffAircraftCreationIntervals m_CreationIntervals;

	CTakingOffAircraftCreationMoments m_CreationMoments;


public:
	CAircraftInputData(std::string runwayId, int specialPlaceId, std::string type, int priority,
		bool processingIsNeeded, CTakingOffAircraftCreationIntervals& creationIntervals, 
		CTakingOffAircraftCreationMoments& creationMoments);

	CAircraftInputData() = default;
};

