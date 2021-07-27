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


class DataRandomizer
{
public:
	~DataRandomizer();

protected:
	DataRandomizer();


public:
	/// <summary>
	/// ���������� �������� � �������� ����������� ��������� ��������
	/// </summary>
	/// <param name="minValue"></param>
	/// <param name="maxValue"></param>
	/// <returns></returns>
	static int GetRandomizedValue(int minValue, int maxValue);


	static int GetRandomizedValue(int value, int dispersion, int step);

private:
	static int GetRandomInt(int min, int max);
};

