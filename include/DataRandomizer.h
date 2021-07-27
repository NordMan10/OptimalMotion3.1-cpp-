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


class DataRandomizer
{
public:
	~DataRandomizer();

protected:
	DataRandomizer();


public:
	/// <summary>
	/// Возвращает значение в пределах переданного интервала значений
	/// </summary>
	/// <param name="minValue"></param>
	/// <param name="maxValue"></param>
	/// <returns></returns>
	static int GetRandomizedValue(int minValue, int maxValue);


	static int GetRandomizedValue(int value, int dispersion, int step);

private:
	static int GetRandomInt(int min, int max);
};

