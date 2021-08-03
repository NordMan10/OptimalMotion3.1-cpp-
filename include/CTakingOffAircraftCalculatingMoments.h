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
private:
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


public:
	int GetPossibleTakingOff() const { return m_PossibleTakingOff; }

	void SetPossibleTakingOff(int possibleMoment) { m_PossibleTakingOff = possibleMoment; }

	int GetPermittedTakingOff() const { return m_PermittedTakingOff; }

	void SetPermittedTakingOff(int permittedMoment) { m_PermittedTakingOff = permittedMoment; }

	int GetReservePermittedTakingOff() const { return m_ReservePermittedTakingOff; }

	void SetReservePermittedTakingOff(int reservePermittedTakingOff) { m_ReservePermittedTakingOff = reservePermittedTakingOff; }

	int GetStart() const { return m_Start; }

	void SetStart(int start) { m_Start = start; }
};

