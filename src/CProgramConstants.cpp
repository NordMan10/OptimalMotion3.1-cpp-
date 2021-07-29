#include "../include/CProgramConstants.h"

CProgramConstants::CProgramConstants()
{
}

CProgramConstants* CProgramConstants::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new  CProgramConstants{ };

	return m_Instance;
}