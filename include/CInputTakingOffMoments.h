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


class CInputTakingOffMoments
{

public:
	/**
	 * �������� ������� ������.
	 */
	std::vector<int> m_PlannedMoments;

	/**
	 * ����������� ������� ������.
	 */
	std::vector<int> m_PermittedMoments;

private:
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
	std::vector<int>& GetUnusedPlannedMoments(std::vector<int>& unusedPlannedMoments);

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedTakingOffMomentIndex();
};

