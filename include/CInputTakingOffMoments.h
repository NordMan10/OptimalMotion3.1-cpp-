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

class CInputTakingOffMoments
{

public:
	/// <summary>
	/// �������� ������� ������
	/// </summary>
	vector<int> m_PlannedMoments;

	/// <summary>
	/// ����������� ������� ������
	/// </summary>
	vector<int> m_PermittedMoments;

private:
	/// <summary>
	/// ������ ���������� ��������������� ��������� �������
	/// </summary>
	int m_LastPlannedTakingOffMomentIndex = -1;

	/// <summary>
	/// ������ ���������� ��������������� ������������ �������
	/// </summary>
	int m_LastPermittedMomentIndex = -1;


public:
	// Default constructor
	CInputTakingOffMoments();

	CInputTakingOffMoments(vector<int>& plannedMoments, vector<int>& permittedMoments);

	// Copy constructor.
	CInputTakingOffMoments(const CInputTakingOffMoments& from);


public:
	/// <summary>
	/// ���������� ����� ������ ���������������� ����������� ������ ������
	/// </summary>
	/// <returns></returns>
	int GetNextPermittedMoment();

	/// <summary>
	/// ���������� ��������� ����������� ������ ��� ����������� ���������� �������, ���� ��� �������� ����������. 
	/// ���� ����������, ���������� null
	/// </summary>
	/// <param name="possibleMoment"></param>
	/// <returns></returns>
	int* GetNearestPermittedMoment(int possibleMoment);

	/// <summary>
	/// ���������� ������ ���������������� �������� ��������
	/// </summary>
	/// <returns></returns>
	vector<int>& GetUnusedPlannedMoments();

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedTakingOffMomentIndex();
};

