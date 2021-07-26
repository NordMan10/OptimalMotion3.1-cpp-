#pragma once
#include <vector>

using namespace std;

/// <summary>
/// —одержит набор плановых и разрешенных моментов взлета и методы дл€ работы с ними
/// </summary>
class InputTakingOffMoments
{

public:
	InputTakingOffMoments(vector<int> plannedMoments, vector<int> permittedMoments);

	/// <summary>
	/// ѕлановые моменты взлета
	/// </summary>
	vector<int> m_PlannedMoments;

	/// <summary>
	/// –азрешенные моменты взлета
	/// </summary>
	vector<int> m_PermittedMoments;

	/// <summary>
	/// ¬озвращает самый первый неиспользованный разрешенный момент взлета
	/// </summary>
	/// <returns></returns>
	int GetNextPermittedMoment();

	/// <summary>
	/// ¬озвращаем ближайший разрешенный момент дл€ переданного возможного момента, если его возможно установить. 
	/// ≈сли невозможно, возвращает null
	/// </summary>
	/// <param name="possibleMoment"></param>
	/// <returns></returns>
	int* GetNearestPermittedMoment(int possibleMoment);

	/// <summary>
	/// ¬озвращает список неиспользованных плановых моментов
	/// </summary>
	/// <returns></returns>
	vector<int> GetUnusedPlannedMoments();

	void ResetLastPlannedTakingOffMomentIndex();

	void ResetLastPermittedMomentIndex();


private:
	/// <summary>
	/// »ндекс последнего использованного планового момента
	/// </summary>
	int m_LastPlannedTakingOffMomentIndex = -1;

	/// <summary>
	/// »ндекс последнего использованного разрешенного момента
	/// </summary>
	int m_LastPermittedMomentIndex = -1;
};

