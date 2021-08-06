#pragma once
/** ��a���� �������� ������
 * ��������������� ����� ��� ������ vector<T> � ��������������� �������� ������ � ���.
 *
 * File  : CVectorHelper.h
 * Author: Yury Ten.
 *
 * ������� �������� ������
 *
 */
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>

 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //


class CVectorHelper
{
public:
	/**
	 * ����������, ����������� �������� �� �����������.
	 *
	 * \param a ������ �������.
	 * \param b ������ �������.
	 * \return �������� bool, ������������, ������ �� ������ �������, ��� ������, ��� ���.
	 */
	template <class T>
	static bool AscendingComparer(T a, T b)
	{
		return a < b;
	}

	/**
	 * ����������, ����������� �������� �� ��������.
	 *
	 * \param a ������ �������.
	 * \param b ������ �������.
	 * \return �������� bool, ������������, ������ �� ������ �������, ��� ������, ��� ���.
	 */
	template <class T>
	static bool DescendingComparer(T a, T b)
	{
		return a > b;
	}

	/**
	 * ��������� ���������� ������ ��������� � ������� ����������� �����������.
	 * 
	 * \param list ������ ���������.
	 * \param comparer ���������� ��� ��������� ���� T.
	 * \return ����� ��������������� ������ ���������.
	 */
	template <class T>
	static std::shared_ptr<std::vector<T>> Sort(std::vector<T>& list, bool comparer(T, T) = AscendingComparer)
	{
		auto newList = std::shared_ptr<std::vector<T>>(new std::vector<T>(list));
		sort(newList->begin(), newList->end(), comparer);

		return newList;
	}

	/**
	 * ����������, �������� �� ���������� ������ ��������� ��������� �������.
	 * 
	 * \param list ������ ���������.
	 * \param element �������, ������� �������� ����� ����������.
	 * \return �������� bool, ������������, �������� �� ������ ��������� �������.
	 */
	template <class T>
	static bool IsContains(std::vector<T>& list, T element)
	{
		if (std::find(list.begin(), list.end(), element) != list.end())
			return true;
		else 
			return false;
	}

	/**
	 * ���������� ������ ���������� �������� � ���������� ������, �������� ������� �������� � ���.
	 * ���� ������ �� �������� ���������� ��������, ����������� ������.
	 * 
	 * \param list ������ ���������.
	 * \param element �������, ������ �������� ����� �����.
	 * \return ������ ���������� ��������.
	 */
	template <class T>
	static int IndexOf(std::vector<T>& list, T element)
	{
		auto begin = list.begin();
		auto end = list.end();

		auto elementIterator = find(begin, end, element);

		assert(elementIterator != end && "The list doesn't contain the element!");

		return elementIterator - begin;
	}
};

