#pragma once

#include <algorithm>
#include "../include/CInputTakingOffMoments.h"
#include "../include/CCommonInputData.h"


CInputTakingOffMoments::CInputTakingOffMoments() 
{
	m_PlannedMoments = std::vector<int>();
	m_PermittedMoments = std::vector<int>();
}


CInputTakingOffMoments::CInputTakingOffMoments(std::vector<int> plannedMoments, std::vector<int> permittedMoments)
{
	m_PlannedMoments = plannedMoments;
	m_PermittedMoments = permittedMoments;
}

CInputTakingOffMoments::CInputTakingOffMoments(const CInputTakingOffMoments& from) :
    m_PlannedMoments(from.m_PlannedMoments), m_PermittedMoments(from.m_PermittedMoments)
{

}

int CInputTakingOffMoments::GetNextPermittedMoment()
{
    return m_PermittedMoments[++m_LastPermittedMomentIndex];
}

int* CInputTakingOffMoments::GetNearestPermittedMoment(int possibleMoment)
{
    auto orderedPermittedMoments = m_PermittedMoments;

    // Упорядочиваем разрешенные моменты
    sort(orderedPermittedMoments.begin(), orderedPermittedMoments.end());

    // Выбираем только те, что еще не были использованы
    auto begin = orderedPermittedMoments.cbegin();
    auto end = orderedPermittedMoments.cbegin() + m_LastPermittedMomentIndex + 1;
    orderedPermittedMoments.erase(begin, end);


    // Проверяем каждый разрешенный момент
    for(int permittedMoment : orderedPermittedMoments)
    {
        auto commonInputDataPtr = CCommonInputData::GetSpareArrivalTimeInterval();
        auto commonInputData = *(commonInputDataPtr);

        // Если разрешенный момент больше или равен возможному + резервное время прибытия => возвращаем его
        if (permittedMoment - commonInputData.m_StartMoment >= possibleMoment)
        {
            auto it = find(begin, end, permittedMoment);
            m_LastPermittedMomentIndex = it - orderedPermittedMoments.cbegin();

            int* result = new int(permittedMoment);
            return result;
        }
    }

    return nullptr;
}

std::vector<int>& CInputTakingOffMoments::GetUnusedPlannedMoments(std::vector<int>& unusedPlannedMoments)
{
	// Упорядочиваем разрешенные моменты
    unusedPlannedMoments = m_PlannedMoments;
    std::sort(unusedPlannedMoments.begin(), unusedPlannedMoments.end());

	// Отбираем еще не использованные плановые моменты
	auto begin = unusedPlannedMoments.cbegin();
	auto end = unusedPlannedMoments.cbegin() + m_LastPlannedTakingOffMomentIndex + 1;
    unusedPlannedMoments.erase(begin, end);

	// Увеличиваем индекс последнего использованного планового момента на количество
	// неиспользованных (потому что подразумевается, что раз их взяли, то они уже использованы)
    m_LastPlannedTakingOffMomentIndex += unusedPlannedMoments.size();

	return unusedPlannedMoments;
}

void CInputTakingOffMoments::ResetLastPlannedTakingOffMomentIndex()
{
    m_LastPlannedTakingOffMomentIndex = -1;
}

void CInputTakingOffMoments::ResetLastPermittedTakingOffMomentIndex()
{
	m_LastPermittedMomentIndex= -1;
}