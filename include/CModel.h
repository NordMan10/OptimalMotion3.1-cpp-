#pragma once


/** Крaткое описание класса
 * Основной класс. Содержит главный метод GetOutputData().
 *
 * File  : CModel.h
 * Author: Yury Ten
 *
 * Длинное описание класса
 * Содержит главный метод GetOutputData(), инициирующий работу всей программы, и вспомогательные методы.
 * Метод GetOutputData() предоставляет выходные данные для их графического представления
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
	 * Список ВПП.
	 */
	std::vector<std::shared_ptr<CRunway>> m_Runways = std::vector<std::shared_ptr<CRunway>>{};

	/**
	 * Список Спец. площадок.
	 */
	std::vector<std::shared_ptr<CSpecialPlace>> m_SpecialPlaces = std::vector<std::shared_ptr<CSpecialPlace>>{};

private:
	/**
	 * Генератор входящих данных для кождого ВС.
	 */
	std::shared_ptr<CAircraftInputDataGenerator> m_AircraftInputDataGenerator = CAircraftInputDataGenerator::GetInstance();


public:
	CModel();

	CModel(int runwayCount, int specialPlaceCount);


public:
	std::vector<std::shared_ptr<CRunway>> GetRunways() const;
	
	std::vector<std::shared_ptr<CSpecialPlace>> GetSpecialPleces() const;

	/**
	 * Главный метод программы, инициирующий начало всей работы. На основе заданных и сгенерированных входящих данных 
	 * рассчитывает все необходимые выходные данные и предоставляет их в виде списка экземпляров класса CTableRow. 
	 * 
	 * \param unusedPlannedTakingOffMoments Список неиспользованных плановых моментов взлета
	 * \return Список выходящих данных, содержащий экземпляры класса CTableRow, представляющие строки таблицы с выходными данными
	 */
	std::shared_ptr<std::vector<std::shared_ptr<CTableRow>>> GetOutputData(std::vector<int>& unusedPlannedTakingOffMoments);

private:
	/**
	 * Создает заданное количество ВПП.
	 * 
	 * \param runwayCount Количество ВПП
	 */
	void InitRunways(int runwayCount);

	/**
	 * Создает заданное количество Спец. площадок.
	 * 
	 * \param specPlatformCount Количество Спец. площадок
	 */
	void InitSpecialPlaces(int specPlatformCount);

	/**
	 * Создает список ВС на основе переданных плановых моментов старта, рассчитывает возможный момент вылета и соответствующий 
	 * ему момент старта для каждого ВС.
	 * 
	 * \param plannedTakingOffMoments Список плановых моментов взлета
	 * \return Возвращает упорядоченный по возможным моментам список ВС с заданными возможными моментами взлета и соответствующими моментами старта.
	 */
	std::shared_ptr<std::vector<std::shared_ptr<CTakingOffAircraft>>> GetOrderedConfiguredTakingOffAircrafts(std::vector<int>& plannedTakingOffMoments);

	/**
	 * На основе переданного списка ВС с заданными возможными моментами взлета и моментами старта определяет возможность назначения и 
	 * допустимое количество резервных ВС для каждого ВС, которое уже не назначено резервным. Находит и задает разрешенные моменты взлета для всех ВС.
	 * Рассчитывает и задает новые моменты старта для резервных ВС. 
	 * 
	 * \param orderedTakingOffAircrafts Список ВС с заданными возможными моментами взлета и моментами старта 
	 */
	void ReconfigureAircraftsWithReserve(std::vector<std::shared_ptr<CTakingOffAircraft>>& orderedTakingOffAircrafts);

	/**
	 * Рассчитывает и задает время ожидания на ПРДВ для переданных ВС.
	 * 
	 * \param takingOffAircrafts Список ВС
	 */
	void SetPSWaitingTime(std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts);

	/**
	 * Создает экземпляр класса CTableRow и заполняет его выходными данными ВС.
	 * 
	 * \param aircraft ВС, выходные данные которого нужно представить
	 * \return Экземпляр класса CTableRow, представляющих формат выходных данных.
	 */
	std::shared_ptr<CTableRow> GetTableRow(CTakingOffAircraft& aircraft) const;

	/**
	 * Рассчитывает задержку момента старта от ВПП. Задержка может образоваться из-за занятости ВПП другим ВС.
	 * 
	 * \param takingOffAircraft ВС, для которого нужно рассчитать задержку.
	 * \param takingOffInterval Интервал взлета ВС (время, которое он будет занимать ВПП).
	 * \return Величину задержки в секундах .
	 */
	int GetRunwayStartDelay(std::shared_ptr<CTakingOffAircraft> takingOffAircraft, CInterval& takingOffInterval) const;

	/**
	 * Рассчитывает задержку момента старта от Спец. площадки. Задержка может образоваться из-за занятости Спец. площадки другим ВС.
	 * 
	 * \param takingOffAircraft ВС, для которого нужно рассчитать задержку.
	 * \param SPArriveMoment Момент прибытия ВС Спец. площадку.
	 * \return Величину задержки в секундах.
	 */
	int GetSpecialPlaceStartDelay(CTakingOffAircraft& takingOffAircraft, int SPArriveMoment) const;

	/**
	 * Рассчитывает моменты старта для резервных ВС по заданному разрешенному моменту.
	 * 
	 * \param permittedMoment Разрешенный момент.
	 * \param mainAircraftIndex Индекс ВС в общем списке, которое является основным, опорным по отношению к резервным ВС. 
	 * \param orderedTakingOffAircrafts Общий список ВС.
	 * \return Словарь, с ключами в виде индексов ВС и значениями в виде моментов старта.
	 */
	std::shared_ptr<std::map<int, int>> GetReserveAircraftsStartMoments(int permittedMoment, int mainAircraftIndex,
		std::vector<std::shared_ptr<CTakingOffAircraft>>& orderedTakingOffAircrafts) const;

	/**
	 * На основе заданного в классе CCommonInputData критерия допустимого количества резервных ВС и переданного разрешенного момента 
	 * определяет возможное количество резервных ВС для переданного по индексу ВС.
	 * 
	 * \param permittedMoment Разрешенный момент.
	 * \param aircraftIndex Индекс ВС, для которого нужно найти возможное количество резервных ВС.
	 * \param possibleTakingOffMoments Список возможных моментов взлета.
	 * \return Возможное количество резервных ВС для переданного ВС.
	 */
	int GetReserveAircraftCount(int permittedMoment, int aircraftIndex, std::vector<int>& possibleTakingOffMoments) const;

	/**
	 * Задает заранее подготовленные и переданные моменты старта для переданных ВС.
	 * 
	 * \param aircraftsStartMomentData Моменты старта.
	 * \param takingOffAircrafts Список ВС.
	 */
	void SetPreparedStartMoments(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts);

	/**
	 * Определяет индекс ВС с наибольшим приоритетом из всех переданных ВС.
	 * 
	 * \param aircraftsStartMomentData Набор данных о ВС и их моментах старта.
	 * \param takingOffAircrafts Список ВС.
	 * \return Найденный индекс ВС.
	 */
	int GetMostPriorityAircraftIndex(std::map<int, int>& aircraftsStartMomentData, std::vector<std::shared_ptr<CTakingOffAircraft>>& takingOffAircrafts) const;
};

