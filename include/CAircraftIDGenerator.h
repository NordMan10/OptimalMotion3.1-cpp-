#pragma once

/** ��a���� �������� ������
 * ����� ��� ��������� ���������� Id ��� ��. ��������
 * File  : CAircraftIDGenerator.h
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


class CAircraftIDGenerator
{
private:
	int m_InitIdValue;
	int m_Id;

public:
	~CAircraftIDGenerator();

	static CAircraftIDGenerator& GetInstance(int initIdValue);

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
	CAircraftIDGenerator(int id);
};

