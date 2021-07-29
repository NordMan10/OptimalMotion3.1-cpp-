#pragma once
class CInterval
{
public:
	int m_StartMoment;
	int m_EndMoment;


public:
	CInterval(int firstMoment = 0, int lastMoment = 0);

	CInterval(const CInterval& from);


public:
	CInterval operator+(const CInterval& summand);


public:
	/// <summary>
	/// ��������� ����������� ����������
	/// </summary>
	/// <param name="interval"></param>
	/// <returns></returns>
	bool IsIntervalsIntersects(const CInterval& interval);

	/// <summary>
	/// ���������� true, ���� ���������� ������ �������� � ������ �������� (������� �������), � false, ���� ���
	/// </summary>
	/// <param name="moment"></param>
	/// <returns></returns>
	bool IsMomentInInterval(int moment) const;
};

