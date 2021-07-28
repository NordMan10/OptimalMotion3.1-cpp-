#include "../include/CTakingOffAircraftCreationIntervals.h"


CTakingOffAircraftCreationIntervals::CTakingOffAircraftCreationIntervals
	(
		int motionFromParkingToPS, int motionFromPSToES, int takingOff,
		int motionFromParkingToSP, int motionFromSPToPS, int processing
	)
{
	m_MotionFromParkingToPS = motionFromParkingToPS;
	m_MotionFromPSToES = m_MotionFromPSToES;
	m_TakingOff = takingOff;
	m_MotionFromParkingToSP = motionFromParkingToSP;
	m_MotionFromSPToPS = motionFromSPToPS;
	m_Processing = processing;
}