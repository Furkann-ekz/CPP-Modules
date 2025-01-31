#include "Identify.hpp"

Base* generate()
{
	srand(static_cast<unsigned int>(time(0)));
	int random = rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
	else
		cout << "Unknown type" << endl;
}

void identify(Base& p)
{
	Base* ptr = &p;
	if (dynamic_cast<A*>(ptr))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(ptr))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(ptr))
		cout << "C" << endl;
	else
		cout << "Unknown type" << endl;
}