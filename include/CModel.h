#pragma once


/** ��a���� �������� ������
 * �������� �����. �������� ������� ����� GetOutputData().
 *
 * File  : CModel.h
 * Author: Yury Ten
 *
 * ������� �������� ������
 * �������� ������� ����� GetOutputData(), ������������ ������ ���� ���������, � ��������������� ������.
 * ����� GetOutputData() ������������� �������� ������ ��� �� ������������ �������������
 */

 // SYSTEM INCLUDES
 //
#include <vector>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CRunway.h"
#include "CSpecialPlace.h"
#include "CAircraftInputDataGenerator.h"
#include "CTableRow.h"
#include "CTakingOffAircraft.h"

class CModel
{
private:
	/**
	 * ������ ���.
	 */
	std::vector<std::shared_ptr<CRunway>> m_Runways = std::vector<std::shared_ptr<CRunway>>{};

	/**
	 * ������ ����. ��������.
	 */
	std::vector<std::shared_ptr<CSpecialPlace>> m_SpecialPlaces = std::vector<std::shared_ptr<CSpecialPlace>>{};

private:
	/**
	 * ��������� �������� ������ ��� ������� ��.
	 */
	std::shared_ptr<CAircraftInputDataGenerator> m_AircraftInputDataGenerator = CAircraftInputDataGenerator::GetInstance();


public:
	CModel();

	CModel(int runwayCount, int specialPlaceCount);


public:
	std::vector<std::shared_ptr<CRunway>> GetRunways() const;
	
	std::vector<std::shared_ptr<CSpecialPlace>> GetSpecialPleces() const;

	/**
	 * ������� ����� ���������, ������������ ������ ���� ������. �� ������ �������� � ��������������� �������� ������ 
	 * ������������ ��� ����������� �������� ������ � ������������� �� � ���� ������ ����������� ������ CTableRow. 
	 * 
	 * \param unusedPlannedTakingOffMoments ������ ���������������� �������� �������� ������
	 * \return ������ ��������� ������, ���������� ���������� ������ CTableRow, �������������� ������ ������� � ��������� �������
	 */
	std::shared_ptr<std::vector<std::shared_ptr<CTableRow>>> GetOutputData(std::vector<int>& unusedPlannedTakingOffMoments);

private:
	/**
	 * ������� �������� ���������� ���.
	 * 
	 * \param runwayCount ���������� ���
	 */
	void InitRunways(int runwayCount);

	/**
	 * ������� �������� ���������� ����. ��������.
	 * 
	 * \param specPlatformCount ���������� ����. ��������
	 */
	void InitSpecialPlaces(int specPlatformCount);

	/**
	 * ������� ������ �� �� ������ ���������� �������� �������� ������, ������������ ��������� ������ ������ � ��������������� 
	 * ��� ������ ������ ��� ������� ��.
	 * 
	 * \param plannedTakingOffMoments ������ �������� �������� ������
	 * \return ���������� ������������� �� ��������� �������� ������ �� � ��������� ���������� ��������� ������ � ���������������� ��������� ������.
	 */
	std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments);

	/**
	 * �� ������ ����������� ������ �� � ��������� ���������� ��������� ������ � ��������� ������ ���������� ����������� ���������� � 
	 * ���������� ���������� ��������� �� ��� ������� ��, ������� ��� �� ��������� ���������. ������� � ������ ����������� ������� ������ ��� ���� ��.
	 * ������������ � ������ ����� ������� ������ ��� ��������� ��. 
	 * 
	 * \param orderedTakingOffAircrafts ������ �� � ��������� ���������� ��������� ������ � ��������� ������ 
	 */
	void ReconfigureAircraftsWithReserve(std::vector<std::shared_ptr<CTakingOffAircraft>>& orderedTakingOffAircrafts);

	/**
	 * ������������ � ������ ����� �������� �� ���� ��� ���������� ��.
	 * 
	 * \param takingOffAircrafts ������ ��
	 */
	void SetPSWaitingTime(std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts);

	/**
	 * ������� ��������� ������ CTableRow � ��������� ��� ��������� ������� ��.
	 * 
	 * \param aircraft ��, �������� ������ �������� ����� �����������
	 * \return ��������� ������ CTableRow, �������������� ������ �������� ������.
	 */
	std::shared_ptr<CTableRow> GetTableRow(CTakingOffAircraft& aircraft) const;

	/**
	 * ������������ �������� ������� ������ �� ���. �������� ����� ������������ ��-�� ��������� ��� ������ ��.
	 * 
	 * \param takingOffAircraft ��, ��� �������� ����� ���������� ��������.
	 * \param takingOffInterval �������� ������ �� (�����, ������� �� ����� �������� ���).
	 * \return �������� �������� � �������� .
	 */
	int GetRunwayStartDelay(std::shared_ptr<CTakingOffAircraft> takingOffAircraft, CInterval& takingOffInterval) const;

	/**
	 * ������������ �������� ������� ������ �� ����. ��������. �������� ����� ������������ ��-�� ��������� ����. �������� ������ ��.
	 * 
	 * \param takingOffAircraft ��, ��� �������� ����� ���������� ��������.
	 * \param SPArriveMoment ������ �������� �� ����. ��������.
	 * \return �������� �������� � ��������.
	 */
	int GetSpecialPlaceStartDelay(CTakingOffAircraft& takingOffAircraft, int SPArriveMoment) const;

	/**
	 * ������������ ������� ������ ��� ��������� �� �� ��������� ������������ �������.
	 * 
	 * \param permittedMoment ����������� ������.
	 * \param mainAircraftIndex ������ �� � ����� ������, ������� �������� ��������, ������� �� ��������� � ��������� ��. 
	 * \param orderedTakingOffAircrafts ����� ������ ��.
	 * \return �������, � ������� � ���� �������� �� � ���������� � ���� �������� ������.
	 */
	std::shared_ptr<std::map<int, int>> GetReserveAircraftsStartMoments(int permittedMoment, int mainAircraftIndex,
		std::vector<std::shared_ptr<CTakingOffAircraft>>& orderedTakingOffAircrafts) const;

	/**
	 * �� ������ ��������� � ������ CCommonInputData �������� ����������� ���������� ��������� �� � ����������� ������������ ������� 
	 * ���������� ��������� ���������� ��������� �� ��� ����������� �� ������� ��.
	 * 
	 * \param permittedMoment ����������� ������.
	 * \param aircraftIndex ������ ��, ��� �������� ����� ����� ��������� ���������� ��������� ��.
	 * \param possibleTakingOffMoments ������ ��������� �������� ������.
	 * \return ��������� ���������� ��������� �� ��� ����������� ��.
	 */
	int GetReserveAircraftCount(int permittedMoment, int aircraftIndex, std::vector<int>& possibleTakingOffMoments) const;

	/**
	 * ������ ������� �������������� � ���������� ������� ������ ��� ���������� ��.
	 * 
	 * \param aircraftsStartMomentData ������� ������.
	 * \param takingOffAircrafts ������ ��.
	 */
	void SetPreparedStartMoments(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts);

	/**
	 * ���������� ������ �� � ���������� ����������� �� ���� ���������� ��.
	 * 
	 * \param aircraftsStartMomentData ����� ������ � �� � �� �������� ������.
	 * \param takingOffAircrafts ������ ��.
	 * \return ��������� ������ ��.
	 */
	int GetMostPriorityAircraftIndex(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts) const;
};

