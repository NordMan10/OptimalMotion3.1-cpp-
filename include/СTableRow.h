#pragma once

/** Крaткое описание класса
 * Представление объекта Строки Таблицы. Поля класса определяют столбцы. По сути — это формат выходных данных
 *
 * File  : ClassName.h
 * Author:
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


class СTableRow
{
public:
	std::string m_AircraftId;

	std::string m_PlannedTakingOffMoment;

	std::string m_PossibleTakingOffMoment;

	std::string m_PermittedTakingOffMoment;

	std::string m_StartMoment;

	std::string m_TotalMotionTime;

	std::string ms_ProcessingTime;

	bool m_NeedProcessing;

	std::string m_AircraftPriority;

	bool m_IsReserved;

	std::string m_PSWaitingTime;

	std::string m_RunwayId;

	std::string m_SpecialPlaceId;


public:
	СTableRow(std::string aircraftId, std::string plannedTakingOffMoment, std::string possibleTakingOffMoment,
		std::string permittedTakingOffMoment, std::string startMoment, std::string totalMotionTime, std::string processingTime, bool
		needProcessing, std::string prioriry, bool isReserved, std::string m_PSWaitingTime, std::string runwayId, std::string specialPlaceId);
	
};

