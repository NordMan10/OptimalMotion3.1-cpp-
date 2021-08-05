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
	

	
	 /**
	  * ���������� ��������� ����� � �������� ����������� ��������� ��������.
	  * 
	  * \param min
	  * \param max
	  * \return 
	  */
	static int GetRandomInt(int min, int max);

	/**
	 * ���������� ��������� ����� � �������� ����� � ��������� �� �������� ��������.
	 * 
	 * \param value ������� ��������
	 * \param dispersion �������
	 * \param step ���
	 * \return ����� �����
	 */
	static int GetRandomizedValue(int value, int dispersion, int step);
};

