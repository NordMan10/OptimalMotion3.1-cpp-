#include "../include/CInterval.h"

CInterval::CInterval(int startMoment, int endMoment)
{
	m_StartMoment = startMoment;
	m_EndMoment = endMoment;
}

bool CInterval::IsIntervalsIntersects(CInterval& interval)
{
	return interval.m_EndMoment > m_StartMoment && interval.m_StartMoment < m_EndMoment;
}

bool CInterval::IsMomentInInterval(int moment)
{
	return m_StartMoment <= moment && m_EndMoment >= moment;
}

CInterval CInterval::operator+(const CInterval& interval) const
{
	return CInterval(m_StartMoment + interval.m_StartMoment, m_EndMoment + interval.m_EndMoment);
}