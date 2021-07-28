#pragma once

/** ��a���� �������� ������
 * �����-���� ����������� ��������, ����� ��� ����� �������
 * File  : ProgramConstants.h
 * Author:
 *
 * ������� �������� ������
 *
 */

class CProgramConstants
{
public:
	/// <summary>
	/// ��������� �������� Id ��� ��� ��������� ������������
	/// </summary>
	static int ms_StartIdValue;

public:
	~CProgramConstants();

private:
	CProgramConstants(int startIdValue);
	

public:
	static CProgramConstants& GetInstance(int startIdValue = 1);
};

