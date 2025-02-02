#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::endl;
using std::cout;
using std::string;

template <typename T, typename Func>
void iter(T *array, size_t length, Func func)
{
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

template <typename T>
void printElement(const T &element)
{
	cout << element << " ";
}

#endif