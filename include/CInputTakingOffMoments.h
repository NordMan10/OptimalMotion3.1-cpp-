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

using namespace std;

/**
 * .
 */

class CInputTakingOffMoments
{

public:
	/**
	 * �������� ������� ������.
	 */
	vector<int> m_PlannedMoments;

	/**
	 * ����������� ������� ������.
	 */
	vector<int> m_PermittedMoments;

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
	CInputTakingOffMoments(vector<int>& plannedMoments, vector<int>& permittedMoments);

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
	vector<int>& GetUnusedPlannedMoments(vector<int>& unusedPlannedMoments);

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedTakingOffMomentIndex();
};

