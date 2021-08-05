#pragma once

/** Крaткое описание класса
 * Представление интервала времени
 *
 * File  : CInterval.h
 * Author:
 *
 * Длинное описание класса
 * Класс, представляющий интервал времени. Определяется начальным и конечным моментами. 
 * Имеет методы для работы с интервалами.
 */

 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CInterval
{
private:
	/**
	 * Начальный момент.
	 */
	int m_StartMoment;

	/**
	 * Конечный момент.
	 */
	int m_EndMoment;


public:
	CInterval(int firstMoment = 0, int lastMoment = 0);

	CInterval(const CInterval& from);


public:
	/**
	 * Переопределяет оператор сложения.
	 * 
	 * \param summand Слагаемое, интервал, прибаляемый к текущему интервалу.
	 * \return Новый интервал
	 */
	CInterval operator+(const CInterval& summand);


public:
	int GetStartMoment() const { return m_StartMoment; }

	int GetEndMoment() const { return m_EndMoment; }

	/**
	 * Проверяет пересечение интервалов.
	 * 
	 * \param interval Интервал, с которым нужно проверить пересечение текущего интервала.
	 * \return Значение типа bool, определяющее наличие пересечения
	 */
	bool IsIntervalsIntersects(const CInterval& interval) const;

	/**
	 * Проверяет, не попадает ли переданный момент в текущий интервал.
	 * 
	 * \param moment Значение момента
	 * \return Значение true, если переданным момент попадаем в данный интервал (включая границы), и false, если нет.
	 */
	bool IsMomentInInterval(int moment) const;
};

