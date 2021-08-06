#pragma once

/** ��a���� �������� ������
 * ������������� ���������������� ������
 *
 * File  : CPreliminaryStart.h
 * Author: Yury Ten
 *
 * ������� �������� ������
 *
 */

 // SYSTEM INCLUDES
 //
#include <map>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CInterval.h"
#include "IMassServiceZone.h"

class CPreliminaryStart : public IMassServiceZone
{
private:
	int m_Id = 0;

	/**
	 * ������ ���������� ��������� ���� (�����, ����� ���� ����� ��).
	 */
	std::map<int, CInterval> m_OccupiedIntervals = std::map<int, CInterval>();


public:
	CPreliminaryStart(int id);


public:
	int GetId() const;

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


