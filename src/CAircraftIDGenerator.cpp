#include "../include/CAircraftIDGenerator.h"

CAircraftIDGenerator::CAircraftIDGenerator(int initIdValue)
{
	m_InitIdValue = initIdValue;
	m_Id = initIdValue;
}

std::shared_ptr<CAircraftIDGenerator> CAircraftIDGenerator::GetInstance(int initIdValue)
{
	if(!m_Instance)
		m_Instance = std::shared_ptr<CAircraftIDGenerator>(new CAircraftIDGenerator(initIdValue));

	return m_Instance;
}

std::shared_ptr<CAircraftIDGenerator> CAircraftIDGenerator::m_Instance = nullptr;

int CAircraftIDGenerator::GetUniqueAircraftId()
{
	return m_Id++;
}

void CAircraftIDGenerator::Reset()
{
	m_Id = m_InitIdValue;
}