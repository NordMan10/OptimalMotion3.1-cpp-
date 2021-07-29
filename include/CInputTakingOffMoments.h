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

using namespace std;

/**
 * .
 */

class CInputTakingOffMoments
{

public:
	/**
	 * ѕлановые моменты взлета.
	 */
	vector<int> m_PlannedMoments;

	/**
	 * –азрешенные моменты взлета.
	 */
	vector<int> m_PermittedMoments;

private:
	/**
	 * »ндекс последнего использованного планового момента.
	 */
	int m_LastPlannedTakingOffMomentIndex = -1;

	/**
	 * »ндекс последнего использованного разрешенного момента.
	 */
	int m_LastPermittedMomentIndex = -1;


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
	CInputTakingOffMoments(vector<int>& plannedMoments, vector<int>& permittedMoments);

	// Copy constructor.
	CInputTakingOffMoments(const CInputTakingOffMoments& from);


public:
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
	vector<int>& GetUnusedPlannedMoments(vector<int>& unusedPlannedMoments);

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedTakingOffMomentIndex();
};

