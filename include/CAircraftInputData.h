#pragma once

/** Крaткое описание класса
 * Набор входных данных, необходимый для каждого ВС
 *
 * File  : CAircraftInputData.h
 * Author: Yury Ten.
 *
 * Длинное описание класса
 * Класс определяем набор входных данных, необходимый для каждого ВС и предоставляем методы доступа к ним
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
	/**
	 * Id ВПП.
	 */
	std::string m_RunwayId;

	/**
	 * Id Спец. площадки.
	 */
	int m_SpecialPlaceId;

	/**
	 * Тип ВС.
	 */
	std::string m_Type;

	/**
	 * Приоритет ВС.
	 */
	int m_Priority;

	/**
	 * Флаг необходимости противообледенительной обработки.
	 */
	bool m_ProcessingIsNeeded;

	/**
	 * Моменты ВС, задающиеся при создании ВС.
	 */
	std::shared_ptr<CTakingOffAircraftCreationMoments> m_CreationMoments;

	/**
	 * Интервалы Вс, задающиеся при создании ВС.
	 */
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

