#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

using std::cout;
using std::endl;

struct Data
{
	int number;
	std::string text;
};

class Serializer
{
	private:
		Serializer();

	public:
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
