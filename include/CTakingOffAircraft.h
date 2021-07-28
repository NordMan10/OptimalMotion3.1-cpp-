#pragma once

/** Крaткое описание класса
 * Представление взлетающего ВС
 *
 * File  : CTakingOffAircraft.h
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
#include "CTakingOffAircraftCreationIntervals.h"
#include "CTakingOffAircraftCreationMoments.h"
#include "CTakingOffAircraftCalculatingMoments.h"
#include "CTakingOffAircraftCalculatingIntervals.h"
#include "CAircraftInputData.h"


class CTakingOffAircraft
{
public:
	int m_Id;

	std::string m_Type;

	int m_Priority;

	CTakingOffAircraftCreationMoments m_CreationMoments;

	CTakingOffAircraftCalculatingMoments m_CalculatingMoments;

	CTakingOffAircraftCreationIntervals m_CreationIntervals;

	CTakingOffAircraftCalculatingIntervals m_CalculatingIntervals;

	bool m_ProcessingIsNeeded;

	bool m_IsReserve;

	std::string m_RunwayId;

	int m_SpecialPlaceId;


public:
	CTakingOffAircraft(int id, const CAircraftInputData& inputData);

	CTakingOffAircraft() = default;
};

