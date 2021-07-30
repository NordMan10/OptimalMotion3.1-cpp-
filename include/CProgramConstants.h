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
	static int m_StartIdValue;

	/// <summary>
	/// ����� ������� �� �������� �� ����
	/// </summary>
	static int m_MotionFromParkingToPS;

	/// <summary>
	/// ����� ������� �� ���� �� ���
	/// </summary>
	static int m_MotionFromPSToES;

	/// <summary>
	/// ����� ������� �� �������� �� ����. ��������
	/// </summary>
	static int m_MotionFromParkingToSP;

	/// <summary>
	/// ����� ������� �� ����. �������� �� ����
	/// </summary>
	static int m_MotionFromSPToPS;

	/// <summary>
	/// ����� ������
	/// </summary>
	static int m_TakingOffInterval;

	/// <summary>
	/// ����� ���������
	/// </summary>
	static int m_ProcessingTime;

};