#pragma once

/** Крaткое описание класса
 * Представление объекта Строки Таблицы. Поля класса определяют столбцы. По сути — это формат выходных данных
 *
 * File  : CTableRow.h
 * Author: Yury Ten.
 *
 * Длинное описание класса
 * 
 *
 */

 // SYSTEM INCLUDES
 //
#include <string>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CTableRow
{
private:
	/**
	 * Id ВС.
	 */
	std::string m_AircraftId;

	/**
	 * Плановый момент взлета ВС.
	 */
	std::string m_PlannedTakingOffMoment;

	/**
	 * Возможный момент взлета ВС.
	 */
	std::string m_PossibleTakingOffMoment;

	/**
	 * Разрешенный момент взлета ВС.
	 */
	std::string m_PermittedTakingOffMoment;

	/**
	 * Момент старта ВС со стоянки.
	 */
	std::string m_StartMoment;

	/**
	 * Общее время движения без учета времени обработки и простоев.
	 */
	std::string m_TotalMotionTime;

	/**
	 * Время противообледенительной обработки.
	 */
	std::string m_ProcessingTime;

	/**
	 * Признак необходимости обработки.
	 */
	bool m_NeedProcessing;

	/**
	 * Приоритет ВС.
	 */
	std::string m_AircraftPriority;

	/**
	 * Признак резервного ВС.
	 */
	bool m_IsReserved;

	/**
	 * Время ожидания на ПРДВ.
	 */
	std::string m_PSWaitingTime;

	/**
	 * Id ВПП, назначенной данному ВС.
	 */
	std::string m_RunwayId;
	
	/**
	 * Id Спец. площадки, назначенной данному ВС.
	 */
	std::string m_SpecialPlaceId;


public:
	CTableRow(std::string aircraftId, std::string plannedTakingOffMoment, std::string possibleTakingOffMoment,
		std::string permittedTakingOffMoment, std::string startMoment, std::string totalMotionTime, std::string processingTime, bool
		needProcessing, std::string prioriry, bool isReserved, std::string PSWaitingTime, std::string runwayId, std::string specialPlaceId);


public:
	std::string GetAircraftId() const { return m_AircraftId; }

	std::string GetPlannedTakingOffMoment() const { return m_PlannedTakingOffMoment; }

	std::string GetPossibleTakingOffMoment() const { return m_PossibleTakingOffMoment; }

	std::string GetPermittedTakingOffMoment() const { return m_PermittedTakingOffMoment; }

	std::string GetStartMoment() const { return m_StartMoment; }

	std::string GetTotalMotionTime() const { return m_TotalMotionTime; }

	std::string GetProcessingTime() const { return m_ProcessingTime; }

	bool GetProcessingNecessity() const { return m_NeedProcessing; }

	std::string GetAircraftPriority() const { return m_AircraftPriority; }

	bool GetIsReserved() const { return m_IsReserved; }

	std::string GetPSWaitingTime() const { return m_PSWaitingTime; }

	std::string GetRunwayId() const { return m_RunwayId; }

	std::string GetSpecialPlaceId() const { return m_SpecialPlaceId; }
};

