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
	std::vector<int> m_OrderedPlannedMoments = std::vector<int>();

	/**
	 * ����������� ������� ������.
	 */
	std::vector<int> m_OrderedPermittedMoments = std::vector<int>();

	/**
	 * ������ ���������� ��������������� ��������� �������.
	 */
	int m_LastPlannedTakingOffMomentIndex = -1;

	/**
	 * ������ ���������� ��������������� ������������ �������.
	 */
	int m_LastPermittedMomentIndex = -1;



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
	std::vector<int> GetPlannedMoments() const { return m_OrderedPlannedMoments; }

	std::vector<int> GetPermittedMoments() const { return m_OrderedPermittedMoments; }

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

