#pragma once

/** Крaткое описание класса
 * Содержит набор плановых и разрешенных моментов взлета и методы для работы с ними
 * File  : CInputTakingOffMoments.h
 * Author: Yury Ten
 *
 * Длинное описание класса
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
	/// <summary>
	/// Плановые моменты взлета
	/// </summary>
	vector<int> m_PlannedMoments;

	/// <summary>
	/// Разрешенные моменты взлета
	/// </summary>
	vector<int> m_PermittedMoments;

private:
	/// <summary>
	/// Индекс последнего использованного планового момента
	/// </summary>
	int m_LastPlannedTakingOffMomentIndex = -1;

	/// <summary>
	/// Индекс последнего использованного разрешенного момента
	/// </summary>
	int m_LastPermittedMomentIndex = -1;


public:
	// Default constructor
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
	/// <summary>
	/// Возвращает самый первый неиспользованный разрешенный момент взлета
	/// </summary>
	/// <returns></returns>
	int GetNextPermittedMoment();

	/// <summary>
	/// Возвращаем ближайший разрешенный момент для переданного возможного момента, если его возможно установить. 
	/// Если невозможно, возвращает nullptr. 
	/// </summary>
	/// <param name="possibleMoment"></param>
	/// <returns>Необходимо удалить объект, полученный через указатель</returns>
	int* GetNearestPermittedMoment(int possibleMoment);

	/// <summary>
	/// Возвращает список неиспользованных плановых моментов
	/// </summary>
	/// <returns></returns>
	vector<int>& GetUnusedPlannedMoments();

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedTakingOffMomentIndex();
};

