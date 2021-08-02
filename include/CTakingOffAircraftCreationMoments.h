#pragma once

/** ��a���� �������� ������
 * �������, ���������� �� ������� ������ ��� ����������� ��
 *
 * File  : TakingOffAircraftCreationMoments	.h
 * Author:
 *
 * ������� �������� ������
 *
 */

class CTakingOffAircraftCreationMoments
{
private:
	/// <summary>
	/// �������� ������ ������
	/// </summary>
	int m_PlannedTakingOff = 0;


public:
	CTakingOffAircraftCreationMoments(int plannedTakingOff);
	CTakingOffAircraftCreationMoments() = default;


public:
	int GetPlannedTakingOff() const;
};

