#pragma once

/** Крaткое описание класса
 * Набор рассчитываемых моментов для взлетающего ВС.
 * 
 * File  : TakingOffAircraftCalculatingMoments.h
 * Author: Yury Ten.
 *
 * Длинное описание класса
 *
 */

class CTakingOffAircraftCalculatingMoments
{
private:
	/**
	 * Возможный момент взлета.
	 */
	int m_PossibleTakingOff = 0;

	/**
	 * Разрешенный момент взлета.
	 */
	int m_PermittedTakingOff = 0;

	/**
	 * Разрешенный момент взлета для резервного ВС (представляет разрешенный момент взлета, который использует резервное ВС, если 
	 * все пройдет в штатном режиме и оно останется резервным (ему не придется заменять основное ВС).
	 */
	int m_ReservePermittedTakingOff = 0;

	/**
	 * Момент старта.
	 */
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

