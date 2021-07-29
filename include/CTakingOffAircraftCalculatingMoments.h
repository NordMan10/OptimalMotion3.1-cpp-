#pragma once

/** ��a���� �������� ������
 * �������������� ������� ��� ����������� ��
 * 
 * File  : TakingOffAircraftCalculatingMoments.h
 * Author:
 *
 * ������� �������� ������
 *
 */

class CTakingOffAircraftCalculatingMoments
{
public:
	/// <summary>
	/// ��������� ������ ������
	/// </summary>
	int m_PossibleTakingOff = 0;

	/// <summary>
	/// ����������� ������ ������
	/// </summary>
	int m_PermittedTakingOff = 0;

	/// <summary>
	/// ����������� ������ ������ ��� ���������� �� (������������ ����������� ������ ������, ������� ���������� ��������� ��, ����
	/// ��� ������� � ������� ������ � ��� ��������� ��������� (��� �� �������� �������� �������� ��)
	/// </summary>
	int m_ReservePermittedTakingOff = 0;

	/// <summary>
	/// ������ ������ 
	/// </summary>
	int m_Start = 0;


public:
	CTakingOffAircraftCalculatingMoments() { };
};

