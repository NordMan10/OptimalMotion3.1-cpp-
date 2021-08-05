#pragma once

/** ��a���� �������� ������
 * �������� ����� �������� � ����������� �������� ������ � ������ ��� ������ � ����
 * File  : CInputTakingOffMoments.h
 * Author: Yury Ten
 *
 * ������� �������� ������
 *
 */

 // SYSTEM INCLUDES
#include <vector>
#include <memory>


class CInputTakingOffMoments
{

private:
	/**
	 * �������� ������� ������.
	 */
	std::shared_ptr<std::vector<int>> m_OrderedPlannedMoments = nullptr;

	/**
	 * ����������� ������� ������.
	 */
	std::shared_ptr<std::vector<int>> m_OrderedPermittedMoments = nullptr;

	/**
	 * ������ ���������� ��������������� ��������� �������.
	 */
	int m_LastPlannedTakingOffMomentIndex = -1;

	/**
	 * ������ ���������� ��������������� ������������ �������.
	 */
	int m_LastPermittedMomentIndex = -1;



public:
	CInputTakingOffMoments();

	CInputTakingOffMoments(std::vector<int>& plannedMoments, std::vector<int>& permittedMoments);

	CInputTakingOffMoments(const CInputTakingOffMoments& from);


public:
	const std::vector<int>& GetPlannedMoments() const { return *m_OrderedPlannedMoments; }

	const std::vector<int>& GetPermittedMoments() const { return *m_OrderedPermittedMoments; }

	/**
	 * ���������� ���������������� ����������� ������ ������, ��������� �� ��������� �������������� 
	 * 
	 * \return �������� ������� ���� int.
	 */
	int GetNextPermittedMoment();

	/**
	 * ���������� ��������� ����������� ������ ��� ����������� ���������� �������, ���� ��� �������� ����������.
	 * ���� ����������, ���������� nullptr. ����� ������������� ��������� ����� �������.
	 * 
	 * \param possibleMoment ��������� ������, ��� �������� ����� ����� ����������� ������
	 * \return �������� ������� ���� int.
	 */
	int* GetNearestPermittedMoment(int possibleMoment);

	/**
	 * ���������� ������ ���������������� �������� ��������.
	 * 
	 * \return ������ �� ���������� ������
	 */
	std::shared_ptr<std::vector<int>> GetUnusedPlannedMoments();

	/**
	 * ���������� �������� ������� ���������� ��������������� ��������� ������� �� ��������� ��������, ������ -1.
	 * 
	 */
	void ResetLastPlannedTakingOffMomentIndex();

	/**
	 * ���������� �������� ������� ���������� ��������������� ������������ ������� �� ��������� ��������, ������ -1..
	 * 
	 */
	void ResetLastPermittedTakingOffMomentIndex();
};

