#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cerr;

template <typename T>
class Array
{
	private :
		T *arr;
		unsigned int len;
	public :
		Array() : arr(0) , len(0) {}

		Array(unsigned int n)
		{
			arr = new T[n];
			len = n;
		}

		Array(const Array &obj)
		{
			*this = obj;
		}

		Array &operator = (const Array &obj)
		{
			if (this == &obj)
				return *this;
			len = obj.size();
			arr = new T[len];
			
			for(unsigned int j = 0; j < len; j++)
				arr[j] = obj.arr[j];
			return *this;
		}

		T &operator [] (unsigned int i)
		{
			if (i >= len)
				throw std::out_of_range("invalid value");
			else
				return arr[i];
		}

		~Array()
		{
			delete [] arr; 
		}

		unsigned int size()
		{
			return len;
		}
};

#endif