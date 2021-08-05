#pragma once

#include <algorithm>
#include <cassert>
#include "../include/CInputTakingOffMoments.h"
#include "../include/CCommonInputData.h"
#include "../include/CVectorHelper.h"


CInputTakingOffMoments::CInputTakingOffMoments() 
{
	m_OrderedPlannedMoments = std::vector<int>();
	m_OrderedPermittedMoments = std::vector<int>();
}


CInputTakingOffMoments::CInputTakingOffMoments(std::vector<int> plannedMoments, std::vector<int> permittedMoments)
{
	m_OrderedPlannedMoments = plannedMoments;
    sort(m_OrderedPlannedMoments.begin(), m_OrderedPlannedMoments.end());
	m_OrderedPermittedMoments = permittedMoments;
	sort(m_OrderedPermittedMoments.begin(), m_OrderedPermittedMoments.end());
}

CInputTakingOffMoments::CInputTakingOffMoments(const CInputTakingOffMoments& from) :
    m_OrderedPlannedMoments(from.m_OrderedPlannedMoments), m_OrderedPermittedMoments(from.m_OrderedPermittedMoments)
{

}

int CInputTakingOffMoments::GetNextPermittedMoment()
{
    //assert(m_LastPermittedMomentIndex < m_OrderedPermittedMoments.size());
    return m_OrderedPermittedMoments[++m_LastPermittedMomentIndex];
}

int* CInputTakingOffMoments::GetNearestPermittedMoment(int possibleMoment)
{
    // ������� ����� ������ ����������� ��������
    auto orderedPermittedMoments = m_OrderedPermittedMoments;

    //  ������� ��� �������������� �������
	auto begin = orderedPermittedMoments.begin();
	auto end = orderedPermittedMoments.begin() + (m_LastPermittedMomentIndex + 1);
    orderedPermittedMoments.erase(begin, end);

    // ��������� ������ ����������� ������
    for(auto permittedMoment : orderedPermittedMoments)
    {
        // ���� ����������� ������ - ������������ ����� �������� ������ ��� ����� ���������� => ���������� ���
        if (permittedMoment - CCommonInputData::GetSpareArrivalTimeInterval().m_StartMoment >= possibleMoment)
        {
            m_LastPermittedMomentIndex = CVectorHelper::IndexOf(m_OrderedPermittedMoments, permittedMoment);

            return new int(permittedMoment);
        }
    }

    return nullptr;
}

std::shared_ptr<std::vector<int>> CInputTakingOffMoments::GetUnusedPlannedMoments()
{
	//������� ����� ������ �������� ��������
    auto unusedPlannedMoments = std::shared_ptr<std::vector<int>>(new std::vector<int>(m_OrderedPlannedMoments));

    // ������������� �������� �������
    std::sort(unusedPlannedMoments->begin(), unusedPlannedMoments->end());

	// �������� ��� �� �������������� �������� �������
	auto begin = unusedPlannedMoments->begin();
	auto end = unusedPlannedMoments->begin() + (m_LastPlannedTakingOffMomentIndex + 1);
    unusedPlannedMoments->erase(begin, end);

	// ����������� ������ ���������� ��������������� ��������� ������� �� ����������
	// ���������������� (������ ��� ���������������, ��� ��� �� �����, �� ��� ��� ������������)
    m_LastPlannedTakingOffMomentIndex += (int)unusedPlannedMoments->size();

	return unusedPlannedMoments;
}

void CInputTakingOffMoments::ResetLastPlannedTakingOffMomentIndex()
{
    m_LastPlannedTakingOffMomentIndex = -1;
}

void CInputTakingOffMoments::ResetLastPermittedTakingOffMomentIndex()
{
	m_LastPermittedMomentIndex = -1;
}