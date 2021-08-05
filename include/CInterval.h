#pragma once

/** ��a���� �������� ������
 * ������������� ��������� �������
 *
 * File  : CInterval.h
 * Author:
 *
 * ������� �������� ������
 * �����, �������������� �������� �������. ������������ ��������� � �������� ���������. 
 * ����� ������ ��� ������ � �����������.
 */

 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CInterval
{
private:
	/**
	 * ��������� ������.
	 */
	int m_StartMoment;

	/**
	 * �������� ������.
	 */
	int m_EndMoment;


public:
	CInterval(int firstMoment = 0, int lastMoment = 0);

	CInterval(const CInterval& from);


public:
	/**
	 * �������������� �������� ��������.
	 * 
	 * \param summand ���������, ��������, ����������� � �������� ���������.
	 * \return ����� ��������
	 */
	CInterval operator+(const CInterval& summand);


public:
	int GetStartMoment() const { return m_StartMoment; }

	int GetEndMoment() const { return m_EndMoment; }

	/**
	 * ��������� ����������� ����������.
	 * 
	 * \param interval ��������, � ������� ����� ��������� ����������� �������� ���������.
	 * \return �������� ���� bool, ������������ ������� �����������
	 */
	bool IsIntervalsIntersects(const CInterval& interval) const;

	/**
	 * ���������, �� �������� �� ���������� ������ � ������� ��������.
	 * 
	 * \param moment �������� �������
	 * \return �������� true, ���� ���������� ������ �������� � ������ �������� (������� �������), � false, ���� ���.
	 */
	bool IsMomentInInterval(int moment) const;
};

