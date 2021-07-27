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
	/// ѕровер€ет пересечение интервалов
	/// </summary>
	/// <param name="interval"></param>
	/// <returns></returns>
	bool IsIntervalsIntersects(CInterval& interval);
	
	/// <summary>
	/// ¬озвращает разность между последним и первый моментом
	/// </summary>
	/// <returns></returns>
	int GetIntervalDuration();

	/// <summary>
	/// ¬озвращает true, если переданным момент попадаем в данный интервал (включа€ границы), и false, если нет
	/// </summary>
	/// <param name="moment"></param>
	/// <returns></returns>
	bool IsMomentInInterval(int moment);
};

