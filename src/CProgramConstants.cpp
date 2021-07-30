#include "../include/CProgramConstants.h"

CProgramConstants::CProgramConstants()
{
}

std::shared_ptr<CProgramConstants> CProgramConstants::GetInstance()
{
	if (!m_Instance)
		m_Instance = std::shared_ptr<CProgramConstants>(new CProgramConstants{ });

	return m_Instance;
}