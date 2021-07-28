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
	int m_PossibleTakingOff;

	/// <summary>
	/// ����������� ������ ������
	/// </summary>
	int m_PermittedTakingOff;

	/// <summary>
	/// ����������� ������ ������ ��� ���������� �� (������������ ����������� ������ ������, ������� ���������� ��������� ��, ����
	/// ��� ������� � ������� ������ � ��� ��������� ��������� (��� �� �������� �������� �������� ��)
	/// </summary>
	int m_ReservePermittedTakingOff;

	/// <summary>
	/// ������ ������ 
	/// </summary>
	int m_Start;


public:
	CTakingOffAircraftCalculatingMoments() { };
};

