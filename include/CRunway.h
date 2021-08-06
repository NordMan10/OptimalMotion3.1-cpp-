#pragma once
/** ��a���� �������� ������
 * ������������� ���
 *
 * File  : CRunway.h
 * Author: Yury Ten
 *
 * ������� �������� ������
 *
 */

 // SYSTEM INCLUDES
 //
#include <map>
#include <string>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CInterval.h"
#include "IMassServiceZone.h"


class CRunway : public IMassServiceZone
{
private:
	std::string m_Id;

	/**
	 * ������ ���������� ��������� ��� (�����, ����� ��� ������ ��).
	 */
	std::map<int, CInterval> m_OccupiedIntervals = std::map<int, CInterval>();
	 

public:
	CRunway(std::string id);


public:
	std::string GetId() const;

	/**
	 * ��������� ���������� �������� � ������ ���������� ����, ���� �� �� ������������ � ������������� �����������.
	 * ���������������, ��� ��� ������� ��������� (�� �������������� ��������), ������� ��� ��������� ������� GetFreeInterval().
	 *
	 * \param aircraftId Id ��.
	 * \param freeInterval ������������ ��������� ��������.
	 */
	void AddAircraftInterval(int aircraftId, CInterval& freeInterval);

	/**
	 * ���������, ����� �� �������� ���������� �������� � ������ ��� ������������ ���������� ���� ��� ����������� � ����.
	 * ���� �����, �� ���������� ����� ����������� ���������. ���� ������, �� ������������ �����, ���������������� ��������.
	 *
	 * \param newInterval ��������, ������� ����� ���������.
	 * \return ���������, ���������������� � ������������� ����������� ����, ��������.
	 */
	std::shared_ptr<CInterval> GetFreeInterval(CInterval& newInterval);

	/**
	 * ������� �� ������ ���������� ��������� ���� ��������, ������������� ��, Id �������� ��� �������.
	 *
	 * \param aircraftId Id ��, �������� �������� ����� �������.
	 */
	void RemoveAircraftInterval(int aircraftId);

	/**
	 * ������� ������ ���������� ��������� ����.
	 *
	 */
	void Reset();
};

