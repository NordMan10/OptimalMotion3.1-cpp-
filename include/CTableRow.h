#pragma once

/** ��a���� �������� ������
 * ������������� ������� ������ �������. ���� ������ ���������� �������. �� ���� � ��� ������ �������� ������
 *
 * File  : CTableRow.h
 * Author: Yury Ten.
 *
 * ������� �������� ������
 * 
 *
 */

 // SYSTEM INCLUDES
 //
#include <string>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CTableRow
{
private:
	/**
	 * Id ��.
	 */
	std::string m_AircraftId;

	/**
	 * �������� ������ ������ ��.
	 */
	std::string m_PlannedTakingOffMoment;

	/**
	 * ��������� ������ ������ ��.
	 */
	std::string m_PossibleTakingOffMoment;

	/**
	 * ����������� ������ ������ ��.
	 */
	std::string m_PermittedTakingOffMoment;

	/**
	 * ������ ������ �� �� �������.
	 */
	std::string m_StartMoment;

	/**
	 * ����� ����� �������� ��� ����� ������� ��������� � ��������.
	 */
	std::string m_TotalMotionTime;

	/**
	 * ����� ���������������������� ���������.
	 */
	std::string m_ProcessingTime;

	/**
	 * ������� ������������� ���������.
	 */
	bool m_NeedProcessing;

	/**
	 * ��������� ��.
	 */
	std::string m_AircraftPriority;

	/**
	 * ������� ���������� ��.
	 */
	bool m_IsReserved;

	/**
	 * ����� �������� �� ����.
	 */
	std::string m_PSWaitingTime;

	/**
	 * Id ���, ����������� ������� ��.
	 */
	std::string m_RunwayId;
	
	/**
	 * Id ����. ��������, ����������� ������� ��.
	 */
	std::string m_SpecialPlaceId;


public:
	CTableRow(std::string aircraftId, std::string plannedTakingOffMoment, std::string possibleTakingOffMoment,
		std::string permittedTakingOffMoment, std::string startMoment, std::string totalMotionTime, std::string processingTime, bool
		needProcessing, std::string prioriry, bool isReserved, std::string PSWaitingTime, std::string runwayId, std::string specialPlaceId);


public:
	std::string GetAircraftId() const { return m_AircraftId; }

	std::string GetPlannedTakingOffMoment() const { return m_PlannedTakingOffMoment; }

	std::string GetPossibleTakingOffMoment() const { return m_PossibleTakingOffMoment; }

	std::string GetPermittedTakingOffMoment() const { return m_PermittedTakingOffMoment; }

	std::string GetStartMoment() const { return m_StartMoment; }

	std::string GetTotalMotionTime() const { return m_TotalMotionTime; }

	std::string GetProcessingTime() const { return m_ProcessingTime; }

	bool GetProcessingNecessity() const { return m_NeedProcessing; }

	std::string GetAircraftPriority() const { return m_AircraftPriority; }

	bool GetIsReserved() const { return m_IsReserved; }

	std::string GetPSWaitingTime() const { return m_PSWaitingTime; }

	std::string GetRunwayId() const { return m_RunwayId; }

	std::string GetSpecialPlaceId() const { return m_SpecialPlaceId; }
};

