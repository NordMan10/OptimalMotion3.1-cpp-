#pragma once

#include <memory>
#include <vector>
#include <algorithm>

class CVectorHelper
{
public:
	template <class T>
	static std::shared_ptr<std::vector<T>> Sort(std::vector<T>& list, bool comparer(T, T))
	{
		auto newList = std::shared_ptr<std::vector<T>>(new std::vector<T>(list));
		sort(newList->begin(), newList->end(), comparer);

		return newList;
	}

	/*template<class T1, class T2>
	std::shared_ptr<std::vector<T1>> CVectorHelper::Sort(std::vector<T1>& list, bool comparer(T2, T2));*/

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

	template <class T>
	static bool Contains(std::vector<T>& list, T element)
	{
		if (std::find(list.begin(), list.end(), element) != list.end()) {
			return true;
		}
		else {
			return false;
		}
	}

	template <class T>
	static int IndexOf(std::vector<T>& list, T element)
	{
		auto begin = list.begin();
		auto end = list.end();

		auto elementIterator = find(begin, end, element);
		return elementIterator - begin;
	}
};

