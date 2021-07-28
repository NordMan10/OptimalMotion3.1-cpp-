#pragma once

/** ��a���� �������� ������
 * ����� ��� ��������� ���������� Id ��� ��. ��������
 * File  : AircraftIdGenerator.h
 * Author:
 *
 * ������� �������� ������
 *
 */
 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class AircraftIdGenerator
{
private:
	int m_InitIdValue;
	int m_Id;

public:
	~AircraftIdGenerator();

	static AircraftIdGenerator* GetInstance(int initIdValue);

	/// <summary>
	/// ���������� ���������� Id ��� ��
	/// </summary>
	/// <returns></returns>
	int GetUniqueAircraftId();

	/// <summary>
	/// ���������� �������� Id �� ��������, ����������� ��� ��������
	/// </summary>
	void Reset();

private:
	AircraftIdGenerator(int id);
};

