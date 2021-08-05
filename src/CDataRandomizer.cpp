#include "../include/CDataRandomizer.h"
#include <vector>


int CDataRandomizer::GetRandomInt(int min, int max)
{
	return (int)((max - min) * ((double)rand() / (double)RAND_MAX) + min);
}

int CDataRandomizer::GetRandomizedValue(int value, int dispersion, int step)
{
	if (dispersion == 0 || step == 0)
		return value;
	auto minValue = value - (value * (double)dispersion / 100);
	auto maxValue = value + (value * (double)dispersion / 100);

	auto possibleValues = std::vector<int>{};

	auto possibleValue = minValue;
	while ((int)possibleValue <= maxValue)
	{
		possibleValues.push_back((int)possibleValue);
		possibleValue += step;
	}

	auto valueIndex = GetRandomInt(0, possibleValues.size());

	return possibleValues[valueIndex];
}