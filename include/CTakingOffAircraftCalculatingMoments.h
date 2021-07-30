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
	int m_PossibleTakingOff = 0;

	/// <summary>
	/// Разрешенный момент взлета
	/// </summary>
	int m_PermittedTakingOff = 0;

	/// <summary>
	/// Разрешенный момент взлета для резервного ВС (представляет разрешенный момент взлета, который использует резервное ВС, если
	/// все пройдет в штатном режиме и оно останется резервным (ему не придется заменять основное ВС)
	/// </summary>
	int m_ReservePermittedTakingOff = 0;

	/// <summary>
	/// Момент старта 
	/// </summary>
	int m_Start = 0;


public:
	CTakingOffAircraftCalculatingMoments() { };


public:
	int GetPossibleTakingOff() const;

	int GetPermittedTakingOff() const;

	int GetReservePermittedTakingOff() const;

	int GetStart() const;
};

