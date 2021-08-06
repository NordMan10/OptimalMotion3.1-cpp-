#pragma once

/** ��a���� �������� ������
 * ����� ����������, ���������� �� ������� ������ ��� ����������� ��
 *
 * File  : TakingOffAircraftCreationIntervals.h
 * Author: Yury Ten.
 *
 * ������� �������� ������
 *
 */

class CTakingOffAircraftCreationIntervals
{
private:
	/**
	 * ����� ������� �� �������� �� ����.
	 */
	int m_MotionFromParkingToPS;

	/**
	 * ����� ������� �� ���� �� ���.
	 */
	int m_MotionFromPSToES;

	/**
	 * ����� ������� �� �������� �� ����. ��������.
	 */
	int m_MotionFromParkingToSP;

	/**
	 * ����� ������� �� ����. �������� �� ����.
	 */
	int m_MotionFromSPToPS;

	/**
	 * ����� ���������.
	 */
	int m_Processing;

	/**
	 * ����� ������.
	 */
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

