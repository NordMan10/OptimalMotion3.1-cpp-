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
private:
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
		int motionFromSPToPS, int processing, int takingOff);

	CTakingOffAircraftCreationIntervals() = default;


public:
	int GetMotionFromParkingToPS() const { return m_MotionFromParkingToPS; }

	int GetMotionFromPSToES() const { return m_MotionFromPSToES; }

	int GetMotionFromParkingToSP() const { return m_MotionFromParkingToSP; }

	int GetMotionFromSPToPS() const { return m_MotionFromSPToPS; }

	int GetProcessing() const { return m_Processing; }

	int GetTakingOff() const { return m_TakingOff; }

};

