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

class CTakingOffAircraftCreationIntervals
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
	/// ����� ���������
	/// </summary>
	int m_Processing;

	/// <summary>
	/// ����� ������
	/// </summary>
	int m_TakingOff;


public:
	CTakingOffAircraftCreationIntervals(
		int motionFromParkingToPS, int motionFromPSToES, int motionFromParkingToSP,
		int motionFromSPToPS, int processing, int takeoff);

	CTakingOffAircraftCreationIntervals() = default;


public:
	int GetMotionFromParkingToPS() const;

	int GetMotionFromPSToES() const;

	int GetMotionFromParkingToSP() const;

	int GetMotionFromSPToPS() const;

	int GetProcessing() const;

	int GetTakingOff() const;

};

