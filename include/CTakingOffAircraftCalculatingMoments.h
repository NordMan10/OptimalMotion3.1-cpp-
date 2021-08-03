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
private:
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
	int GetPossibleTakingOff() const { return m_PossibleTakingOff; }

	void SetPossibleTakingOff(int possibleMoment) { m_PossibleTakingOff = possibleMoment; }

	int GetPermittedTakingOff() const { return m_PermittedTakingOff; }

	void SetPermittedTakingOff(int permittedMoment) { m_PermittedTakingOff = permittedMoment; }

	int GetReservePermittedTakingOff() const { return m_ReservePermittedTakingOff; }

	void SetReservePermittedTakingOff(int reservePermittedTakingOff) { m_ReservePermittedTakingOff = reservePermittedTakingOff; }

	int GetStart() const { return m_Start; }

	void SetStart(int start) { m_Start = start; }
};

