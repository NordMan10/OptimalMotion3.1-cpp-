#pragma once

/** Крaткое описание класса
 * Класс для рандомизации значений
 * File  : DataRandomizer.h
 * Author:
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
	  * \param min
	  * \param max
	  * \return 
	  */
	static int GetRandomInt(int min, int max);

	/**
	 * Возвращает случайное число с заданным шагом и разбросом от среднего значения.
	 * 
	 * \param value Среднее значение
	 * \param dispersion Разброс
	 * \param step Шаг
	 * \return Целое число
	 */
	static int GetRandomizedValue(int value, int dispersion, int step);
};

