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
#include <memory>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CAircraftIDGenerator
{
private:
	int m_InitIdValue;
	int m_Id;
	static std::shared_ptr<CAircraftIDGenerator> m_Instance;


public:
	~CAircraftIDGenerator() {};

private:
	CAircraftIDGenerator(int id);


public:
	static std::shared_ptr<CAircraftIDGenerator> GetInstance(int initIdValue);

	/// <summary>
	/// ���������� ���������� Id ��� ��
	/// </summary>
	/// <returns></returns>
	int GetUniqueAircraftId();

	/// <summary>
	/// ���������� �������� Id �� ��������, ����������� ��� ��������
	/// </summary>
	void Reset();

};

