#pragma once

/** ��a���� �������� ������
 * �����-���� ����������� ��������, ����� ��� ����� �������
 * File  : ProgramConstants.h
 * Author:
 *
 * ������� �������� ������
 *
 */

class CProgramConstants
{
public:
	/// <summary>
	/// ��������� �������� Id ��� ��� ��������� ������������
	/// </summary>
	int m_StartIdValue = 1;

	/// <summary>
	/// ����� ������� �� �������� �� ����
	/// </summary>
	int m_MotionFromParkingToPS = 240;

	/// <summary>
	/// ����� ������� �� ���� �� ���
	/// </summary>
	int m_MotionFromPSToES = 40;

	/// <summary>
	/// ����� ������� �� �������� �� ����. ��������
	/// </summary>
	int m_MotionFromParkingToSP = 120;

	/// <summary>
	/// ����� ������� �� ����. �������� �� ����
	/// </summary>
	int m_MotionFromSPToPS = 120;

	/// <summary>
	/// ����� ������
	/// </summary>
	int m_TakingOffInterval = 30;

	/// <summary>
	/// ����� ���������
	/// </summary>
	int m_ProcessingTime = 240;
	
private:
	static CProgramConstants* m_Instance;


public:
	~CProgramConstants();

private:
	CProgramConstants();
	

public:
	static CProgramConstants* GetInstance();
};

