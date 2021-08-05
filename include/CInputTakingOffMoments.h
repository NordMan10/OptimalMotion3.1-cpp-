#pragma once

/**  рaткое описание класса
 * —одержит набор плановых и разрешенных моментов взлета и методы дл€ работы с ними
 * File  : CInputTakingOffMoments.h
 * Author: Yury Ten
 *
 * ƒлинное описание класса
 *
 */

 // SYSTEM INCLUDES
#include <vector>
#include <memory>


class CInputTakingOffMoments
{

private:
	/**
	 * ѕлановые моменты взлета.
	 */
	std::shared_ptr<std::vector<int>> m_OrderedPlannedMoments = nullptr;

	/**
	 * –азрешенные моменты взлета.
	 */
	std::shared_ptr<std::vector<int>> m_OrderedPermittedMoments = nullptr;

	/**
	 * »ндекс последнего использованного планового момента.
	 */
	int m_LastPlannedTakingOffMomentIndex = -1;

	/**
	 * »ндекс последнего использованного разрешенного момента.
	 */
	int m_LastPermittedMomentIndex = -1;



public:
	CInputTakingOffMoments();

	CInputTakingOffMoments(std::vector<int>& plannedMoments, std::vector<int>& permittedMoments);

	CInputTakingOffMoments(const CInputTakingOffMoments& from);


public:
	const std::vector<int>& GetPlannedMoments() const { return *m_OrderedPlannedMoments; }

	const std::vector<int>& GetPermittedMoments() const { return *m_OrderedPermittedMoments; }

	/**
	 * ¬озвращает неиспользованный разрешенный момент взлета, следующий за последним использованным 
	 * 
	 * \return «начение момента типа int.
	 */
	int GetNextPermittedMoment();

	/**
	 * ¬озвращает ближайший разрешенный момент дл€ переданного возможного момента, если его возможно установить.
	 * ≈сли невозможно, возвращает nullptr. ѕосле использовани€ указатель нужно удалить.
	 * 
	 * \param possibleMoment ¬озможный момент, дл€ которого нужно найти разрешенный момент
	 * \return «начение момента типа int.
	 */
	int* GetNearestPermittedMoment(int possibleMoment);

	/**
	 * ¬озвращает список неиспользованных плановых моментов.
	 * 
	 * \return —сылку на переданный список
	 */
	std::shared_ptr<std::vector<int>> GetUnusedPlannedMoments();

	/**
	 * —брасывает значение индекса последнего использованного планового момента на начальное значение, равное -1.
	 * 
	 */
	void ResetLastPlannedTakingOffMomentIndex();

	/**
	 * —брасывает значение индекса последнего использованного разрешенного момента на начальное значение, равное -1..
	 * 
	 */
	void ResetLastPermittedTakingOffMomentIndex();
};

