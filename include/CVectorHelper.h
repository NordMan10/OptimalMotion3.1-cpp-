#pragma once

#include <memory>
#include <vector>

class CVectorHelper
{
public:
	template <class T>
	static std::shared_ptr<std::vector<T>> Sort(std::vector<T>& list, bool comparer(T, T));

	template <class T>
	static bool AscendingComparer(T a, T b)
	{
		return a < b;
	}

	template <class T>
	static bool DescendingComparer(T a, T b)
	{
		return a > b;
	}
};

