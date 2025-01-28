#include "Identify.hpp"
#include <iostream>

int main()
{
	Base* randomBase = generate();

	std::cout << "Identify by pointer:" << std::endl;
	identify(randomBase);

	std::cout << "Identify by reference:" << std::endl;
	identify(*randomBase);

	delete randomBase;

	return 0;
}