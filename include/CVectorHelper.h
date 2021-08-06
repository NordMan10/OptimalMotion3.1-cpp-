#pragma once
/** Крaткое описание класса
 * Вспомогательный класс для класса vector<T> с дополнительными методами работы с ним.
 *
 * File  : CVectorHelper.h
 * Author: Yury Ten.
 *
 * Длинное описание класса
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
	 * Компаратор, сортирующий элементы по возрастанию.
	 *
	 * \param a Первый элемент.
	 * \param b Второй элемент.
	 * \return Значение bool, определяющее, меньше ли первый элемент, чем второй, или нет.
	 */
	template <class T>
	static bool AscendingComparer(T a, T b)
	{
		return a < b;
	}

	/**
	 * Компаратор, сортирующий элементы по убыванию.
	 *
	 * \param a Первый элемент.
	 * \param b Второй элемент.
	 * \return Значение bool, определяющее, больше ли первый элемент, чем второй, или нет.
	 */
	template <class T>
	static bool DescendingComparer(T a, T b)
	{
		return a > b;
	}

	/**
	 * Сортирует переданный список элементов с помощью полученного компаратора.
	 * 
	 * \param list Список элементов.
	 * \param comparer Компаратор для элементов типа T.
	 * \return Новый отсортированный список элементов.
	 */
	template <class T>
	static std::shared_ptr<std::vector<T>> Sort(std::vector<T>& list, bool comparer(T, T) = AscendingComparer)
	{
		auto newList = std::shared_ptr<std::vector<T>>(new std::vector<T>(list));
		sort(newList->begin(), newList->end(), comparer);

		return newList;
	}

	/**
	 * Определяет, содержит ли переданный список элементов указанный элемент.
	 * 
	 * \param list Список элементов.
	 * \param element Элемент, наличие которого нужно определить.
	 * \return Значение bool, определяющее, содержит ли список указанный элемент.
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
	 * Определяет индекс указанного элемента в переданном списке, проверяя наличие элемента в нем.
	 * Если список не содержит указанного элемента, выбрасывает ошибку.
	 * 
	 * \param list Список элементов.
	 * \param element Элемент, индекс которого нужно найти.
	 * \return Индекс указанного элемента.
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

