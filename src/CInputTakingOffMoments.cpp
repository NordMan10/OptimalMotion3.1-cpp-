#pragma once

#include <algorithm>
#include "../include/CInputTakingOffMoments.h"
#include "../include/CCommonInputData.h"

using namespace std;

CInputTakingOffMoments::CInputTakingOffMoments()
{
	m_PlannedMoments = vector<int>();
	m_PermittedMoments = vector<int>();
}


CInputTakingOffMoments::CInputTakingOffMoments(vector<int>& plannedMoments, vector<int>& permittedMoments)
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
    for(const auto& permittedMoment : orderedPermittedMoments)
    {
        auto commonInputData = CCommonInputData::GetInstance();

        // Если разрешенный момент больше или равен возможному + резервное время прибытия => возвращаем его
        if (permittedMoment - commonInputData.m_SpareArrivalTimeInterval.m_StartMoment >= possibleMoment)
        {
            auto it = find(begin, end, permittedMoment);
            m_LastPermittedMomentIndex = it - orderedPermittedMoments.cbegin();

            auto result = permittedMoment;
            return &result;
        }
    }

    return nullptr;
}

vector<int>& CInputTakingOffMoments::GetUnusedPlannedMoments()
{
	// Упорядочиваем разрешенные моменты
    auto orderedPlannedMoments = m_PlannedMoments;
    sort(orderedPlannedMoments.begin(), orderedPlannedMoments.end());

	// Отбираем еще не использованные плановые моменты
	auto begin = orderedPlannedMoments.cbegin();
	auto end = orderedPlannedMoments.cbegin() + m_LastPlannedTakingOffMomentIndex + 1;
    orderedPlannedMoments.erase(begin, end);

	// Увеличиваем индекс последнего использованного планового момента на количество
	// неиспользованных (потому что подразумевается, что раз их взяли, то они уже использованы)
    m_LastPlannedTakingOffMomentIndex += orderedPlannedMoments.size();

	return orderedPlannedMoments;
}

void CInputTakingOffMoments::ResetLastPlannedTakingOffMomentIndex()
{
    m_LastPlannedTakingOffMomentIndex = -1;
}

void CInputTakingOffMoments::ResetLastPermittedTakingOffMomentIndex()
{
	m_LastPermittedMomentIndex= -1;
}