#include "Identify.hpp"
#include <iostream>

int main()
{
	Base* randomBase = generate();

	cout << "Identify by pointer:" << endl;
	identify(randomBase);

	cout << "Identify by reference:" << endl;
	identify(*randomBase);

	delete randomBase;

	return 0;
}