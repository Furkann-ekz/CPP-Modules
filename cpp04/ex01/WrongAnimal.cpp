#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	cout << "[WrongAnimal] Default constructor called." << endl;
}

WrongAnimal::WrongAnimal(string typ)
{
	type = typ;
	cout << "[WrongAnimal] Constructor called." << endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	if (this != &src)
		*this = src;
	cout << "[WrongAnimal] Copy constructor called." << endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	cout << "[WrongAnimal] Destructor called for " << type << "." << endl;
}

void WrongAnimal::makeSound() const
{
	cout << "WrongAnimal's sound." << endl;
}

string WrongAnimal::getType() const
{
	return (type);
}