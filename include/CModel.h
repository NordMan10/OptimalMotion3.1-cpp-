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

	std::shared_ptr<std::vector<CTakingOffAircraft>> GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments);

	std::vector<CTakingOffAircraft> GetReconfiguredAircraftsWithReserve(std::vector<CTakingOffAircraft>& orderedTakingOffAircrafts);

	void SetPSWaitingTime(std::vector<CTakingOffAircraft>& takingOffAircrafts);

	std::shared_ptr<СTableRow> GetTableRow(CTakingOffAircraft& aircraft);

	int GetRunwayStartDelay(CTakingOffAircraft& takingOffAircraft, CInterval& takingOffInterval);
};

