#pragma once

/** ��a���� �������� ������
 * ���������, ���������� �� ������� ������ ��� ����������� ��
 *
 * File  : TakingOffAircraftCreationIntervals.h
 * Author:
 *
 * ������� �������� ������
 *
 */

class TakingOffAircraftCreationIntervals
{
public:
	/// <summary>
	/// ����� ������� �� �������� �� ����
	/// </summary>
	int m_MotionFromParkingToPS;

	/// <summary>
	/// ����� ������� �� ���� �� ���
	/// </summary>
	int m_MotionFromPSToES;

	/// <summary>
	/// ����� ������� �� �������� �� ����. ��������
	/// </summary>
	int m_MotionFromParkingToSP;

	/// <summary>
	/// ����� ������� �� ����. �������� �� ����
	/// </summary>
	int m_MotionFromSPToPS;

	/// <summary>
	/// ����� ������
	/// </summary>
	int m_TakingOff;

	/// <summary>
	/// ����� ���������
	/// </summary>
	int m_Processing;


public:
	TakingOffAircraftCreationIntervals(
		int motionFromParkingToPS, int motionFromPSToES, int takeoff,
		int motionFromParkingToSP, int motionFromSPToPS, int processing)
};

