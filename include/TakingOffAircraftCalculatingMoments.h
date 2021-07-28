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

class TakingOffAircraftCalculatingMoments
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
	TakingOffAircraftCalculatingMoments() { };
};

