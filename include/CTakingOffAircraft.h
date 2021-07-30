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

	std::shared_ptr<CTakingOffAircraftCreationMoments> m_CreationMoments;

	std::shared_ptr<CTakingOffAircraftCalculatingMoments> m_CalculatingMoments = nullptr;

	std::shared_ptr<CTakingOffAircraftCreationIntervals> m_CreationIntervals;

	std::shared_ptr<CTakingOffAircraftCalculatingIntervals> m_CalculatingIntervals = nullptr;

	bool m_ProcessingIsNeeded;

	bool m_IsReserve;

	std::string m_RunwayId;

	int m_SpecialPlaceId;

private:
	static int ms_IdGenerator;


public:
	CTakingOffAircraft(const CAircraftInputData& inputData);

	CTakingOffAircraft() = default;
};

