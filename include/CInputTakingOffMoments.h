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
	std::vector<int> m_PlannedMoments = std::vector<int>();

	/**
	 * –азрешенные моменты взлета.
	 */
	std::vector<int> m_PermittedMoments = std::vector<int>();

	/**
	 * »ндекс последнего использованного планового момента.
	 */
	int m_NextPlannedTakingOffMomentIndex = -1;

	/**
	 * »ндекс последнего использованного разрешенного момента.
	 */
	int m_NextPermittedMomentIndex = -1;



public:
	/**
	 *  онструктор по умолчанию.
	 * 
	 * \return 
	 */
	CInputTakingOffMoments();

	/**
	 * .
	 * 
	 * \param plannedMoments
	 * \param permittedMoments
	 */
	CInputTakingOffMoments(std::vector<int> plannedMoments, std::vector<int> permittedMoments);

	// Copy constructor.
	CInputTakingOffMoments(const CInputTakingOffMoments& from);


public:
	std::vector<int> GetPlannedMoments() const { return m_PlannedMoments; }

	std::vector<int> GetPermittedMoments() const { return m_PermittedMoments; }

	/**
	 * ¬озвращает самый первый неиспользованный разрешенный момент взлета.
	 * 
	 * \return —амый первый неиспользованный разрешенный момент взлета.
	 */
	int GetNextPermittedMoment();

	/**
	 * ¬озвращает ближайший разрешенный момент дл€ переданного возможного момента, если его возможно установить.
	 * ≈сли невозможно, возвращает nullptr. ѕосле использовани€ указатель нужно удалить.
	 * 
	 * \param possibleMoment
	 * \return 
	 */
	int* GetNearestPermittedMoment(int possibleMoment);

	/**
	 * ¬озвращает список неиспользованных плановых моментов.
	 * 
	 * \param unusedPlannedMoments
	 * \return —сылку на переданный список
	 */
	std::shared_ptr<std::vector<int>> GetUnusedPlannedMoments();

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedTakingOffMomentIndex();
};

