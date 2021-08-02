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

    // ������������� ����������� �������
    sort(orderedPermittedMoments.begin(), orderedPermittedMoments.end());

    // �������� ������ ��, ��� ��� �� ���� ������������
    auto begin = orderedPermittedMoments.cbegin();
    auto end = orderedPermittedMoments.cbegin() + m_LastPermittedMomentIndex + 1;
    orderedPermittedMoments.erase(begin, end);


    // ��������� ������ ����������� ������
    for(int permittedMoment : orderedPermittedMoments)
    {
        auto commonInputDataPtr = CCommonInputData::GetSpareArrivalTimeInterval();
        auto commonInputData = *(commonInputDataPtr);

        // ���� ����������� ������ ������ ��� ����� ���������� + ��������� ����� �������� => ���������� ���
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
	// ������������� ����������� �������
    unusedPlannedMoments = m_PlannedMoments;
    std::sort(unusedPlannedMoments.begin(), unusedPlannedMoments.end());

	// �������� ��� �� �������������� �������� �������
	auto begin = unusedPlannedMoments.cbegin();
	auto end = unusedPlannedMoments.cbegin() + m_LastPlannedTakingOffMomentIndex + 1;
    unusedPlannedMoments.erase(begin, end);

	// ����������� ������ ���������� ��������������� ��������� ������� �� ����������
	// ���������������� (������ ��� ���������������, ��� ��� �� �����, �� ��� ��� ������������)
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