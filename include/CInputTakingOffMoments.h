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
	std::vector<int> m_PlannedMoments = std::vector<int>();

	/**
	 * ����������� ������� ������.
	 */
	std::vector<int> m_PermittedMoments = std::vector<int>();

	/**
	 * ������ ���������� ��������������� ��������� �������.
	 */
	int m_NextPlannedTakingOffMomentIndex = -1;

	/**
	 * ������ ���������� ��������������� ������������ �������.
	 */
	int m_NextPermittedMomentIndex = -1;



public:
	/**
	 * ����������� �� ���������.
	 * 
	 * \return 
	 */
	CInputTakingOffMoments();

	/**
	 * .
	 * 
	 * \param plannedMoments
	 * \param permittedMoments
	 */
	CInputTakingOffMoments(std::vector<int> plannedMoments, std::vector<int> permittedMoments);

	// Copy constructor.
	CInputTakingOffMoments(const CInputTakingOffMoments& from);


public:
	std::vector<int> GetPlannedMoments() const { return m_PlannedMoments; }

	std::vector<int> GetPermittedMoments() const { return m_PermittedMoments; }

	/**
	 * ���������� ����� ������ ���������������� ����������� ������ ������.
	 * 
	 * \return ����� ������ ���������������� ����������� ������ ������.
	 */
	int GetNextPermittedMoment();

	/**
	 * ���������� ��������� ����������� ������ ��� ����������� ���������� �������, ���� ��� �������� ����������.
	 * ���� ����������, ���������� nullptr. ����� ������������� ��������� ����� �������.
	 * 
	 * \param possibleMoment
	 * \return 
	 */
	int* GetNearestPermittedMoment(int possibleMoment);

	/**
	 * ���������� ������ ���������������� �������� ��������.
	 * 
	 * \param unusedPlannedMoments
	 * \return ������ �� ���������� ������
	 */
	std::shared_ptr<std::vector<int>> GetUnusedPlannedMoments();

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedTakingOffMomentIndex();
};

