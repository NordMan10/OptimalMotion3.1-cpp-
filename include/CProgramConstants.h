#pragma once

/** ��a���� �������� ������
 * �����-���� ����������� ��������, ����� ��� ���� ���������
 * File  : ProgramConstants.h
 * Author: Yury Ten
 *
 * ������� �������� ������
 *
 */

// SYSTEM INCLUDES
//

// PROJECT INCLUDES
//

// LOCAL INCLUDES
//


class CProgramConstants
{
public:
	/**
	 * ��������� �������� Id ��� ��� ��������� ������������.
	 */
	static int ms_StartIdValue;

	/**
	 * ����� ������� �� �������� �� ����.
	 */
	static int ms_MotionFromParkingToPS;

	/**
	 * ����� ������� �� ���� �� ���.
	 */
	static int ms_MotionFromPSToES;

	/**
	 * ����� ������� �� �������� �� ����. ��������.
	 */
	static int ms_MotionFromParkingToSP;

	/**
	 * ����� ������� �� ����. �������� �� ����.
	 */
	static int ms_MotionFromSPToPS;

	/**
	 * ����� ������.
	 */
	static int ms_TakingOffInterval;

	/**
	 * ����� ���������.
	 */
	static int ms_ProcessingTime;

};