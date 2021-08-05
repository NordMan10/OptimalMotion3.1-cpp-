#include "../include/CInterval.h"

CInterval::CInterval(int startMoment, int endMoment)
{
	m_StartMoment = startMoment;
	m_EndMoment = endMoment;
}

CInterval::CInterval(const CInterval& from)
{
	m_StartMoment = from.m_StartMoment;
	m_EndMoment = from.m_EndMoment;
}

bool CInterval::IsIntervalsIntersects(const CInterval& interval) const
{
	return interval.m_EndMoment > m_StartMoment && interval.m_StartMoment < m_EndMoment;
}

bool CInterval::IsMomentInInterval(int moment) const
{
	return m_StartMoment <= moment && m_EndMoment >= moment;
}

CInterval CInterval::operator+(const CInterval& interval)
{
	return CInterval(m_StartMoment + interval.m_StartMoment, m_EndMoment + interval.m_EndMoment);
}