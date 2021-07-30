#pragma once

/** Крaткое описание класса
 * Набор входных данных, необходимый для каждого ВС
 *
 * File  : CAircraftInputData.h
 * Author:
 *
 * Длинное описание класса
 *
 */

 // SYSTEM INCLUDES
 //
#include <string>
#include <memory>

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

	std::shared_ptr<CTakingOffAircraftCreationIntervals> m_CreationIntervals;

	std::shared_ptr<CTakingOffAircraftCreationMoments> m_CreationMoments;


public:
	CAircraftInputData(std::string runwayId, int specialPlaceId, std::string type, int priority,
		bool processingIsNeeded, std::shared_ptr<CTakingOffAircraftCreationIntervals> creationIntervals,
		std::shared_ptr<CTakingOffAircraftCreationMoments> creationMoments);

	CAircraftInputData() = default;

	~CAircraftInputData() {};
};

