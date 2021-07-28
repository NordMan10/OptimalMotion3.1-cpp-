#pragma once

/** ��a���� �������� ������
 * �����-���� ����������� ��������, ����� ��� ����� �������
 * File  : ProgramConstants.h
 * Author:
 *
 * ������� �������� ������
 *
 */

class ProgramConstants
{
public:
	/// <summary>
	/// ��������� �������� Id ��� ��� ��������� ������������
	/// </summary>
	static int m_StartIdValue;

public:
	~ProgramConstants();

private:
	ProgramConstants(int startIdValue);
	

public:
	static ProgramConstants& GetInstance(int startIdValue = 1);
};

