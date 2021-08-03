#pragma once

/** ��a���� �������� ������
 * �������������� ��������� ��� ����������� ��
 * File  : TakingOffAircraftCalculatingIntervals.h
 * Author:
 *
 * ������� �������� ������
 *
 */

class CTakingOffAircraftCalculatingIntervals
{
private:
	int m_PSDelay = 0;


public:
	CTakingOffAircraftCalculatingIntervals() {};


public:
	int GetPSDelay() const { return m_PSDelay; }

	void SetPSDelay(int PSDelay) { m_PSDelay = PSDelay; }
};

