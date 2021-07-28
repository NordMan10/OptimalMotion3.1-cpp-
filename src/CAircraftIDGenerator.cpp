#include "../include/CAircraftIDGenerator.h"

CAircraftIDGenerator::CAircraftIDGenerator(int initIdValue)
{
	m_InitIdValue = initIdValue;
	m_Id = initIdValue;
}

CAircraftIDGenerator& CAircraftIDGenerator::GetInstance(int initIdValue)
{
	static CAircraftIDGenerator instance = CAircraftIDGenerator(initIdValue);

	return instance;
}

int CAircraftIDGenerator::GetUniqueAircraftId()
{
	return m_Id++;
}

void CAircraftIDGenerator::Reset()
{
	m_Id = m_InitIdValue;
}