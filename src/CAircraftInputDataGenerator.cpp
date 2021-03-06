#include <string>

#include "../include/CAircraftInputDataGenerator.h"
#include "../include/CProgramConstants.h"
#include "../include/CCommonInputData.h"
#include "../include/CDataRandomizer.h"
#include "../include/Enums/ENU_AIRCRAFT_PRIORITIES.h"


CAircraftInputDataGenerator::CAircraftInputDataGenerator() {}

CAircraftInputDataGenerator::CAircraftInputDataGenerator(CAircraftInputDataGenerator& from) {}

std::shared_ptr<CAircraftInputDataGenerator> CAircraftInputDataGenerator::m_Instance = nullptr;

std::shared_ptr<CAircraftInputDataGenerator> CAircraftInputDataGenerator::GetInstance()
{
	if (!m_Instance)
		m_Instance = std::shared_ptr<CAircraftInputDataGenerator>(new CAircraftInputDataGenerator());

	return m_Instance;
}

std::shared_ptr<CAircraftInputData> CAircraftInputDataGenerator::GetAircraftInputData(int plannedTakingOffMoment)
{
	auto runwayId = std::to_string(CDataRandomizer::GetRandomInt(CProgramConstants::ms_StartIdValue, CCommonInputData::GetRunwayCount() + 1));
	int specialPlaceId = CDataRandomizer::GetRandomInt(CProgramConstants::ms_StartIdValue, CCommonInputData::GetSpecialPlaceCount() + 1);

	std::vector<std::string> aircraftTypes{ "Light", "Medium", "Heavy" };
	std::string aircraftType = std::to_string(rand() % (0 + aircraftTypes.size()));

	auto priority = GetAircraftPriority();

	bool processingIsNeeded = GetProcessingNecessity();

	auto creationMoments = std::shared_ptr<CTakingOffAircraftCreationMoments>(new CTakingOffAircraftCreationMoments(plannedTakingOffMoment));
	auto creationIntervals = GetTakingOffAircraftCreationIntervals();

	return std::shared_ptr<CAircraftInputData>(new CAircraftInputData(runwayId, specialPlaceId, aircraftType, priority, processingIsNeeded, 
		creationMoments, creationIntervals));
}

int CAircraftInputDataGenerator::GetAircraftPriority()
{
	int priority = 0;

	int priorityValue = rand() % (1 + 11);
	if (priorityValue == 1)
		priority = EAP_HIGH;
	else if (priorityValue < 4)
		priority = EAP_MEDIUM;
	else
		priority = EAP_DEFAULT;

	return priority;
}

bool CAircraftInputDataGenerator::GetProcessingNecessity()
{
	auto processingIsNeededVariants = std::vector<bool>{ true, false };
	return processingIsNeededVariants[rand() % (0 + processingIsNeededVariants.size())];
}

std::shared_ptr<CTakingOffAircraftCreationIntervals> CAircraftInputDataGenerator::GetTakingOffAircraftCreationIntervals()
{
	auto motionFromParkingToPS = CDataRandomizer::GetRandomizedValue(CProgramConstants::ms_MotionFromParkingToPS, 25, 15);
	auto motionFromPSToES = CDataRandomizer::GetRandomizedValue(CProgramConstants::ms_MotionFromPSToES, 25, 5);
	auto takingOffInterval = CDataRandomizer::GetRandomizedValue(CProgramConstants::ms_TakingOffInterval, 0, 5);
	auto motionFromParkingToSP = CDataRandomizer::GetRandomizedValue(CProgramConstants::ms_MotionFromParkingToSP, 25, 15);
	auto motionFromSPToPS = CDataRandomizer::GetRandomizedValue(CProgramConstants::ms_MotionFromSPToPS, 25, 15);
	auto processingTime = CDataRandomizer::GetRandomizedValue(CProgramConstants::ms_ProcessingTime, 25, 30);

	return std::shared_ptr<CTakingOffAircraftCreationIntervals>(new CTakingOffAircraftCreationIntervals(motionFromParkingToPS, 
		motionFromPSToES, motionFromParkingToSP, motionFromSPToPS, processingTime, takingOffInterval));
}
