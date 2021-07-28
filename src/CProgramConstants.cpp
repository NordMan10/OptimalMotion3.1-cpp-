#include "../include/CProgramConstants.h"

CProgramConstants::CProgramConstants(int startIdValue)
{
	ms_StartIdValue = startIdValue;
}

CProgramConstants& CProgramConstants::GetInstance(int startIdValue)
{
	static CProgramConstants instance{ startIdValue };

	return instance;
}