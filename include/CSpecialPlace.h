#pragma once
/** ��a���� �������� ������.
 *
 *
 * File  : CSpecialPlace.h
 * Author: Yury Ten.
 *
 * ������� �������� ������
 *
 */
#include <map>

 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CInterval.h"
#include "IMassServiceZone.h"

class CSpecialPlace : public IMassServiceZone
{
private:
	int m_Id = 0;

	/**
	 * ������ ���������� ��������� ���� (�����, ����� ���� ����� ��).
	 */
	std::map<int, CInterval> m_ProcessingIntervals = std::map<int, CInterval>();


public:
	CSpecialPlace(int id);


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