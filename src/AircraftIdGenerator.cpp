#include "../include/AircraftIdGenerator.h"

AircraftIdGenerator::AircraftIdGenerator(int initIdValue)
{
	m_InitIdValue = initIdValue;
	m_Id = initIdValue;
}

AircraftIdGenerator* AircraftIdGenerator::GetInstance(int initIdValue)
{
	static AircraftIdGenerator* instance = new AircraftIdGenerator(initIdValue);

	return instance;
}

int AircraftIdGenerator::GetUniqueAircraftId()
{
	return m_Id++;
}

void AircraftIdGenerator::Reset()
{
	m_Id = m_InitIdValue;
}