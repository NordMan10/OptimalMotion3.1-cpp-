#pragma once

/** ��a���� �������� ������
 * ����� ��� ������������ ��������
 * File  : DataRandomizer.h
 * Author:
 *
 * ������� �������� ������
 *
 */
 // SYSTEM INCLUDES
 //
#include <random>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CDataRandomizer
{
public:
	~CDataRandomizer();

protected:
	CDataRandomizer();


public:
	/// <summary>
	/// ���������� �������� � �������� ����������� ��������� ��������
	/// </summary>
	/// <param name="minValue"></param>
	/// <param name="maxValue"></param>
	/// <returns></returns>
	static int GetRandomInt(int min, int max);

	static int GetRandomizedValue(int value, int dispersion, int step);
};

