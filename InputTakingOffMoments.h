#pragma once
#include <vector>

using namespace std;

/// <summary>
/// �������� ����� �������� � ����������� �������� ������ � ������ ��� ������ � ����
/// </summary>
class InputTakingOffMoments
{

public:
	InputTakingOffMoments(vector<int> plannedMoments, vector<int> permittedMoments);

	/// <summary>
	/// �������� ������� ������
	/// </summary>
	vector<int> m_PlannedMoments;

	/// <summary>
	/// ����������� ������� ������
	/// </summary>
	vector<int> m_PermittedMoments;

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
	vector<int> GetUnusedPlannedMoments();

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedMomentIndex();


private:
	/// <summary>
	/// ������ ���������� ��������������� ��������� �������
	/// </summary>
	int m_LastPlannedTakingOffMomentIndex = -1;

	/// <summary>
	/// ������ ���������� ��������������� ������������ �������
	/// </summary>
	int m_LastPermittedMomentIndex = -1;
};

