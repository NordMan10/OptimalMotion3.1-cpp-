#pragma once

/** Крaткое описание класса
 * Класс для рандомизации значений
 * File  : DataRandomizer.h
 * Author: Yury Ten.
 * 
 * Длинное описание класса
 *
 */
 // SYSTEM INCLUDES
 //
#include <random>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CDataRandomizer
{
public:
	

	
	 /**
	  * Возвращает случайное число в пределах переданного интервала значений.
	  * 
	  * \param min Минимальное значение.
	  * \param max Максимальное значение.
	  * \return Целое число.
	  */
	static int GetRandomInt(int min, int max);

	/**
	 * Возвращает случайное число с заданным шагом и разбросом от среднего значения.
	 * 
	 * \param value Среднее значение.
	 * \param dispersion Разброс в процентах.
	 * \param step Шаг в единицах передаваемой величины.
	 * \return Целое число.
	 */
	static int GetRandomizedValue(int value, int dispersion, int step);
};

