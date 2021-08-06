#pragma once

/** ��a���� �������� ������
 *
 * File  : IMassServiceZone.h
 * Author:
 *
 * ������� �������� ������
 *
 */
 // SYSTEM INCLUDES
 //
#include <memory>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
# include "CInterval.h"


class IMassServiceZone
{
	/**
	 * ���������, ����� �� �������� ���������� �������� � ������ ��� ������������ ���������� ���� ��� ����������� � ����.
	 * ���� �����, �� ���������� ����� ����������� ���������. ���� ������, �� ������������ �����, ���������������� ��������.
	 *
	 * \param newInterval ��������, ������� ����� ���������.
	 * \return ���������, ���������������� � ������������� ����������� ����, ��������.
	 */
    virtual std::shared_ptr<CInterval> GetFreeInterval(CInterval& newInterval) = 0;

	/**
	 * ��������� ���������� �������� � ������ ���������� ����, ���� �� �� ������������ � ������������� �����������.
	 * ���������������, ��� ��� ������� ��������� (�� �������������� ��������), ������� ��� ��������� ������� GetFreeInterval().
	 *
	 * \param aircraftId Id ��.
	 * \param freeInterval ������������ ��������� ��������.
	 */
    virtual void AddAircraftInterval(int aircraftId, CInterval& freeInterval) = 0;

	/**
	 * ������� �� ������ ���������� ��������� ���� ��������, ������������� ��, Id �������� ��� �������.
	 *
	 * \param aircraftId Id ��, �������� �������� ����� �������.
	 */
    virtual void RemoveAircraftInterval(int aircraftId) = 0;

	/**
	 * ������� ������ ���������� ��������� ����.
	 *
	 */
    virtual void Reset() = 0;
};

