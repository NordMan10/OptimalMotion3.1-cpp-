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
private:
	std::string m_RunwayId;

	int m_SpecialPlaceId;

	std::string m_Type;

	int m_Priority;

	bool m_ProcessingIsNeeded;

	std::shared_ptr<CTakingOffAircraftCreationMoments> m_CreationMoments;

	std::shared_ptr<CTakingOffAircraftCreationIntervals> m_CreationIntervals;

public:
	CAircraftInputData(std::string runwayId, int specialPlaceId, std::string type, int priority,
		bool processingIsNeeded, std::shared_ptr<CTakingOffAircraftCreationMoments> creationMoments,
		std::shared_ptr<CTakingOffAircraftCreationIntervals> creationIntervals);

	CAircraftInputData() = default;

	~CAircraftInputData() {};


public:
	std::string GetRunwayId() const { return m_RunwayId; }

	int GetSpecialPlaceId() const { return m_SpecialPlaceId; }

	std::string GetType() const { return m_Type; }

	int GetPriority() const { return m_Priority; }

	bool GetProcessingNecessity() const { return m_ProcessingIsNeeded; }

	std::shared_ptr<CTakingOffAircraftCreationMoments> GetCreationMoments() const { return m_CreationMoments; }

	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetCreationIntervals() const { return m_CreationIntervals; }
};

