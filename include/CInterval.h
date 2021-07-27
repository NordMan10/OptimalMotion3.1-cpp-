#pragma once
class CInterval
{
public:
	int m_StartMoment;
	int m_EndMoment;


public:
	CInterval(int firstMoment = 0, int lastMoment = 0);


public:
	CInterval operator+(const CInterval& summand) const;


public:
	/// <summary>
	/// ��������� ����������� ����������
	/// </summary>
	/// <param name="interval"></param>
	/// <returns></returns>
	bool IsIntervalsIntersects(CInterval& interval);
	
	/// <summary>
	/// ���������� �������� ����� ��������� � ������ ��������
	/// </summary>
	/// <returns></returns>
	int GetIntervalDuration();

	/// <summary>
	/// ���������� true, ���� ���������� ������ �������� � ������ �������� (������� �������), � false, ���� ���
	/// </summary>
	/// <param name="moment"></param>
	/// <returns></returns>
	bool IsMomentInInterval(int moment);
};

