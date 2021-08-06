#pragma once

/** Крaткое описание класса
 * Представление взлетающего ВС
 *
 * File  : CTakingOffAircraft.h
 * Author: Yury Ten
 *
 * Длинное описание класса
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
#include "CTakingOffAircraftCalculatingMoments.h"
#include "CTakingOffAircraftCalculatingIntervals.h"
#include "CAircraftInputData.h"


class CTakingOffAircraft
{
private:
	/**
	 * Id ВС.
	 */
	int m_Id;

	/**
	 * Id ВПП, с которой взлетает ВС.
	 */
	std::string m_RunwayId;

	/**
	 * Id Спец. площадки, на которой обрабатывается ВС.
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
	 * Моменты, задающиеся при создании ВС.
	 */
	std::shared_ptr<CTakingOffAircraftCreationMoments> m_CreationMoments;

	/**
	 * Моменты, рассчитывающиеся в процессе обработки ВС.
	 */
	std::shared_ptr<CTakingOffAircraftCalculatingMoments> m_CalculatingMoments = 
		std::shared_ptr<CTakingOffAircraftCalculatingMoments>(new CTakingOffAircraftCalculatingMoments());

	/**
	 * Интервалы, задающиеся при создании ВС.
	 */
	std::shared_ptr<CTakingOffAircraftCreationIntervals> m_CreationIntervals;

	/**
	 * Интервалы, рассчитывающиеся в процессе обработки ВС.
	 */
	std::shared_ptr<CTakingOffAircraftCalculatingIntervals> m_CalculatingIntervals = 
		std::shared_ptr<CTakingOffAircraftCalculatingIntervals>(new CTakingOffAircraftCalculatingIntervals());

	/**
	 * Признак необходимости обработки.
	 */
	bool m_ProcessingIsNeeded;

	/**
	 * Признак резервного ВС.
	 */
	bool m_IsReserve;

	/**
	 * Последнее значение Id, присвоенное взлетающему ВС. Используется для генерации нового уникального Id.
	 */
	static int ms_NextTakingOffAircraftId;


public:
	CTakingOffAircraft(const CAircraftInputData& inputData);

	CTakingOffAircraft() = default;


public:
	static bool PossibleMomentComparer(std::shared_ptr<CTakingOffAircraft> a1, std::shared_ptr<CTakingOffAircraft> a2);

	static bool PermittedMomentComparer(std::shared_ptr<CTakingOffAircraft> a1, std::shared_ptr<CTakingOffAircraft> a2);

	int GetId() { return m_Id; }

	std::string GetType() { return m_Type; }

	int GetPriority() { return m_Priority; }

	bool GetProcessingNecessity() const { return m_ProcessingIsNeeded; }

	bool GetReserveFlag() const { return m_IsReserve; }
	
	void SetReserveFlag(bool reserveFlag) { m_IsReserve = reserveFlag; }

	std::string GetRunwayId() const { return m_RunwayId; }

	int GetSpecialPlaceId() const { return m_SpecialPlaceId; }

	std::shared_ptr<CTakingOffAircraftCreationMoments> GetCreationMoments() const { return m_CreationMoments; }
	
	std::shared_ptr<CTakingOffAircraftCalculatingMoments> GetCalculatingMoments() const { return m_CalculatingMoments; }
	
	std::shared_ptr<CTakingOffAircraftCreationIntervals> GetCreationIntervals() const { return m_CreationIntervals; }
	
	std::shared_ptr<CTakingOffAircraftCalculatingIntervals> GetCalculatingIntervals() const { return m_CalculatingIntervals; }

private:
	/**
	 * Создает новое уникальное значение Id ВС.
	 * 
	 * \return Id ВС.
	 */
	int GetNewUniqueId();
};

