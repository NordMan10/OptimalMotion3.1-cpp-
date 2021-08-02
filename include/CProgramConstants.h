#pragma once
#include <memory>

/** ��a���� �������� ������
 * �����-���� ����������� ��������, ����� ��� ����� �������
 * File  : ProgramConstants.h
 * Author:
 *
 * ������� �������� ������
 *
 */

// SYSTEM INCLUDES
//
#include <memory>

// PROJECT INCLUDES
//

// LOCAL INCLUDES
//


class CProgramConstants
{
public:
	/// <summary>
	/// ��������� �������� Id ��� ��� ��������� ������������
	/// </summary>
	static int ms_StartIdValue;

	/// <summary>
	/// ����� ������� �� �������� �� ����
	/// </summary>
	static int ms_MotionFromParkingToPS;

	/// <summary>
	/// ����� ������� �� ���� �� ���
	/// </summary>
	static int ms_MotionFromPSToES;

	/// <summary>
	/// ����� ������� �� �������� �� ����. ��������
	/// </summary>
	static int ms_MotionFromParkingToSP;

	/// <summary>
	/// ����� ������� �� ����. �������� �� ����
	/// </summary>
	static int ms_MotionFromSPToPS;

	/// <summary>
	/// ����� ������
	/// </summary>
	static int ms_TakingOffInterval;

	/// <summary>
	/// ����� ���������
	/// </summary>
	static int ms_ProcessingTime;

};