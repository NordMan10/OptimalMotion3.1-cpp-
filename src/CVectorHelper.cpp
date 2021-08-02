#include "../include/CVectorHelper.h"

template<class T>
std::shared_ptr<std::vector<T>> CVectorHelper::Sort(std::vector<T>& list, bool comparer(T, T))
{
	auto newList = std::shared_ptr<std::vector<T>>(new std::vector<T>(list));
	sort(newList->begin(), newList->end(), comparer);

	return newList;
}
