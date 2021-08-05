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

