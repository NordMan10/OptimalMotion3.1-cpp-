#pragma once

/** Крaткое описание класса
 * Рассчитываемые моменты для взлетающего ВС
 * 
 * File  : TakingOffAircraftCalculatingMoments.h
 * Author:
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCalculatingMoments
{
public:
	/// <summary>
	/// Возможный момент взлета
	/// </summary>
	int m_PossibleTakingOff;

	/// <summary>
	/// Разрешенный момент взлета
	/// </summary>
	int m_PermittedTakingOff;

	/// <summary>
	/// Разрешенный момент взлета для резервного ВС (представляет разрешенный момент взлета, который использует резервное ВС, если
	/// все пройдет в штатном режиме и оно останется резервным (ему не придется заменять основное ВС)
	/// </summary>
	int m_ReservePermittedTakingOff;

	/// <summary>
	/// Момент старта 
	/// </summary>
	int m_Start;


public:
	CTakingOffAircraftCalculatingMoments() { };
};

