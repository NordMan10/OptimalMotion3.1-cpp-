#include "../include/CAircraftInputDataGenerator.h"
#include <string>
#include "../include/CProgramConstants.h"
#include "../include/CCommonInputData.h"
#include "../include/CDataRandomizer.h"
#include "../include/Enums/ENU_AIRCRAFT_PRIORITIES.h"


CAircraftInputDataGenerator::CAircraftInputDataGenerator()
{
	m_CommonInputData = CCommonInputData::GetInstance();
	m_ProgramConstants = CProgramConstants::GetInstance();
}

CAircraftInputDataGenerator& CAircraftInputDataGenerator::GetInstance()
{
	static CAircraftInputDataGenerator instance{};

	return instance;
}

CAircraftInputData* CAircraftInputDataGenerator::GetAircraftInputData(int plannedTakingOffMoment)
{
	auto runwayId = std::to_string(rand() % ((*m_ProgramConstants).m_StartIdValue + (*m_CommonInputData).m_RunwayCount + 1));
	int specialPlaceId = CDataRandomizer::GetRandomizedValue((*m_ProgramConstants).m_StartIdValue, (*m_CommonInputData).m_SpecialPlaceCount + 1);

	vector<std::string> aircraftTypes{ "Light", "Medium", "Heavy" };
	std::string aircraftType = std::to_string(rand() % (0 + aircraftTypes.size()));

	auto priority = GetAircraftPriority();

	bool processingIsNeeded = GetProcessingNecessity();

	auto creationMoments = new CTakingOffAircraftCreationMoments(plannedTakingOffMoment);
	auto creationIntervals = GetTakingOffAircraftCreationIntervals();

	return new CAircraftInputData(runwayId, specialPlaceId, aircraftType, priority, processingIsNeeded, creationIntervals, creationMoments);
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
	auto processingIsNeededVariants = vector<bool>{ true, false };
	return processingIsNeededVariants[rand() % (0 + processingIsNeededVariants.size())];
}

CTakingOffAircraftCreationIntervals* CAircraftInputDataGenerator::GetTakingOffAircraftCreationIntervals()
{
	auto motionFromParkingToPS = CDataRandomizer::GetRandomizedValue((*m_ProgramConstants).m_MotionFromParkingToPS, 25, 15);
	auto motionFromPSToES = CDataRandomizer::GetRandomizedValue((*m_ProgramConstants).m_MotionFromPSToES, 25, 5);
	auto takingOffInterval = CDataRandomizer::GetRandomizedValue((*m_ProgramConstants).m_TakingOffInterval, 0, 5);
	auto motionFromParkingToSP = CDataRandomizer::GetRandomizedValue((*m_ProgramConstants).m_MotionFromParkingToSP, 25, 15);
	auto motionFromSPToPS = CDataRandomizer::GetRandomizedValue((*m_ProgramConstants).m_MotionFromSPToPS, 25, 15);
	auto processingTime = CDataRandomizer::GetRandomizedValue((*m_ProgramConstants).m_ProcessingTime, 25, 30);

	return new CTakingOffAircraftCreationIntervals(motionFromParkingToPS, motionFromPSToES, takingOffInterval, motionFromParkingToSP,
		motionFromSPToPS, processingTime);
}
