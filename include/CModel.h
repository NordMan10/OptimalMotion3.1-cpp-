#pragma once


/** Крaткое описание класса
 *
 *
 * File  : ClassName.h
 * Author:
 *
 * Длинное описание класса
 *
 */

 // SYSTEM INCLUDES
 //
#include <vector>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CRunway.h"
#include "CSpecialPlace.h"
#include "CAircraftInputDataGenerator.h"
#include "СTableRow.h"
#include "CTakingOffAircraft.h"

class CModel
{
public:
	std::vector<std::shared_ptr<CRunway>> m_Runways = std::vector<std::shared_ptr<CRunway>>{};

	std::vector<std::shared_ptr<CSpecialPlace>> m_SpecialPlaces = std::vector<std::shared_ptr<CSpecialPlace>>{};

private:
	std::shared_ptr<CAircraftInputDataGenerator> m_AircraftInputDataGenerator = CAircraftInputDataGenerator::GetInstance();


public:
	CModel();

	CModel(int runwayCount, int specialPlaceCount);


public:
	std::vector<std::shared_ptr<CRunway>> GetRunways() const;
	
	std::vector<std::shared_ptr<CSpecialPlace>> GetSpecialPleces() const;

private:
	void InitRunways(int runwayCount);

	void InitSpecialPlaces(int specPlatformCount);

	std::shared_ptr<std::vector<std::shared_ptr<СTableRow>>> GetOutputData(std::vector<int>& unusedPlannedTakingOffMoments);

	std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments);

	std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> GetReconfiguredAircraftsWithReserve(
		std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> orderedTakingOffAircrafts);

	void SetPSWaitingTime(std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts);

	std::shared_ptr<СTableRow> GetTableRow(CTakingOffAircraft& aircraft);

	int GetRunwayStartDelay(std::shared_ptr<CTakingOffAircraft> takingOffAircraft, CInterval& takingOffInterval);

	int GetSpecialPlaceStartDelay(std::shared_ptr<CTakingOffAircraft> takingOffAircraft, CInterval& takingOffInterval, int SPArriveMoment);

	std::shared_ptr<std::map<int, int>> GetReserveAircraftsStartMoments(int permittedMoment, int aircraftIndex,
		std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> orderedTakingOffAircrafts);

	int GetReserveAircraftCount(int permittedMoment, int aircraftIndex, std::vector<int>& possibleTakingOffMoments);

	void SetSPreparedStartMoments(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts);

	int GetMostPriorityAircraftIndex(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts);
};

