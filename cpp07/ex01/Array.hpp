#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <cstdlib>

template <typename T>
class Array
{
	public:
		Array() : _data(NULL), _size(0) {}

		Array(unsigned int n) : _data(NULL), _size(n)
		{
			if (_size > 0)
				_data = new T[_size]();
		}

		Array(const Array<T>& other) : _data(NULL), _size(other._size)
		{
			if (_size > 0)
			{
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_data[i] = other._data[i];
			}
		}

		Array<T>& operator=(const Array<T>& other)
		{
			if (this != &other)
			{
				if (_data)
					delete [] _data;
				_size = other._size;
				if (_size > 0)
				{
					_data = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						_data[i] = other._data[i];
				}
				else
					_data = NULL;
			}
			return *this;
		}

		~Array()
		{
			if (_data)
				delete [] _data;
		}

		T& operator[](int index)
		{
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		const T& operator[](int index) const
		{
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		unsigned int size() const
		{
			return _size;
		}

	private:
		T*				_data;
		unsigned int	_size;
};

#endif
