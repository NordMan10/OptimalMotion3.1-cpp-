#include "../include/ProgramConstants.h"

ProgramConstants::ProgramConstants(int startIdValue)
{
	m_StartIdValue = startIdValue;
}

ProgramConstants& ProgramConstants::GetInstance(int startIdValue = 1)
{
	static ProgramConstants instance{ startIdValue };

	return instance;
}