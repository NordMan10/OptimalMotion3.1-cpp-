#include "../include/CTakingOffAircraftCreationIntervals.h"


CTakingOffAircraftCreationIntervals::CTakingOffAircraftCreationIntervals
	(
		int motionFromParkingToPS, int motionFromPSToES, int motionFromParkingToSP,
		int motionFromSPToPS, int processing, int takingOff
	)
{
	m_MotionFromParkingToPS = motionFromParkingToPS;
	m_MotionFromPSToES = motionFromPSToES;
	m_MotionFromParkingToSP = motionFromParkingToSP;
	m_MotionFromSPToPS = motionFromSPToPS;
	m_Processing = processing;
	m_TakingOff = takingOff;
}

int CTakingOffAircraftCreationIntervals::GetMotionFromParkingToPS() const
{
	return m_MotionFromParkingToPS;
}

int CTakingOffAircraftCreationIntervals::GetMotionFromPSToES() const
{
	return m_MotionFromPSToES;
}

int CTakingOffAircraftCreationIntervals::GetMotionFromParkingToSP() const
{
	return m_MotionFromParkingToSP;
}

int CTakingOffAircraftCreationIntervals::GetMotionFromSPToPS() const
{
	return m_MotionFromSPToPS;
}

int CTakingOffAircraftCreationIntervals::GetProcessing() const
{
	return m_Processing;
}

int CTakingOffAircraftCreationIntervals::GetTakingOff() const
{
	return m_TakingOff;
}

