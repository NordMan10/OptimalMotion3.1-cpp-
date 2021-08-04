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
private:
	int m_Id;

	std::string m_RunwayId;

	int m_SpecialPlaceId;

	std::string m_Type;

	int m_Priority;

	std::shared_ptr<CTakingOffAircraftCreationMoments> m_CreationMoments;

	std::shared_ptr<CTakingOffAircraftCalculatingMoments> m_CalculatingMoments = 
		std::shared_ptr<CTakingOffAircraftCalculatingMoments>(new CTakingOffAircraftCalculatingMoments());

	std::shared_ptr<CTakingOffAircraftCreationIntervals> m_CreationIntervals;

	std::shared_ptr<CTakingOffAircraftCalculatingIntervals> m_CalculatingIntervals = 
		std::shared_ptr<CTakingOffAircraftCalculatingIntervals>(new CTakingOffAircraftCalculatingIntervals());

	bool m_ProcessingIsNeeded;

	bool m_IsReserve;

	static int ms_IdGenerator;


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
};

