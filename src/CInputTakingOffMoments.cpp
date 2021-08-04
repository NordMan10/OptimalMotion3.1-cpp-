#pragma once

#include <algorithm>
#include <cassert>
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
    //assert(m_NextPermittedMomentIndex < m_PermittedMoments.size());
    return m_PermittedMoments[++m_NextPermittedMomentIndex];
}

int* CInputTakingOffMoments::GetNearestPermittedMoment(int possibleMoment)
{
    // ������� ����� ������ ����������� ��������
    auto orderedPermittedMoments = m_PermittedMoments;

    // ������������� ����������� �������
    sort(orderedPermittedMoments.begin(), orderedPermittedMoments.end());

    //  ������� ��� �������������� �������
	auto begin = orderedPermittedMoments.begin();
	auto end = orderedPermittedMoments.begin() + (m_NextPermittedMomentIndex + 1);
    orderedPermittedMoments.erase(begin, end);

    // ��������� ������ ����������� ������
    for(auto permittedMoment : orderedPermittedMoments)
    {
        auto commonInputData = CCommonInputData::GetSpareArrivalTimeInterval();

        // ���� ����������� ������ ������ ��� ����� ���������� + ��������� ����� �������� => ���������� ���
        if (permittedMoment >= possibleMoment + commonInputData.m_StartMoment)
        {
            auto begin = orderedPermittedMoments.begin();
            auto end = orderedPermittedMoments.end();

            auto permittedMomentIterator = find(begin, end, permittedMoment);
            m_NextPermittedMomentIndex = (permittedMomentIterator - begin) - 1;

            return new int(permittedMoment);
        }
    }

    return nullptr;
}

std::shared_ptr<std::vector<int>> CInputTakingOffMoments::GetUnusedPlannedMoments()
{
	//������� ����� ������ �������� ��������
    auto unusedPlannedMoments = std::shared_ptr<std::vector<int>>(new std::vector<int>(m_PlannedMoments));
    // ������������� ����������� �������
    std::sort(unusedPlannedMoments->begin(), unusedPlannedMoments->end());

	// �������� ��� �� �������������� �������� �������
	auto begin = unusedPlannedMoments->begin();
	auto end = unusedPlannedMoments->begin() + (m_NextPlannedTakingOffMomentIndex + 1);
    unusedPlannedMoments->erase(begin, end);

	// ����������� ������ ���������� ��������������� ��������� ������� �� ����������
	// ���������������� (������ ��� ���������������, ��� ��� �� �����, �� ��� ��� ������������)
    m_NextPlannedTakingOffMomentIndex += unusedPlannedMoments->size();

	return unusedPlannedMoments;
}

void CInputTakingOffMoments::ResetLastPlannedTakingOffMomentIndex()
{
    m_NextPlannedTakingOffMomentIndex = -1;
}

void CInputTakingOffMoments::ResetLastPermittedTakingOffMomentIndex()
{
	m_NextPermittedMomentIndex = -1;
}