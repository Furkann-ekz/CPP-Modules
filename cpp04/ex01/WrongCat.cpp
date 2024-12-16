#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	cout << "[WrongCat] Default constructor called." << endl;
}

WrongCat::WrongCat(string typ)
{
	type = typ;
	cout << "[WrongCat] Constructor called." << endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	if (this != &src)
		*this = src;
	cout << "[WrongCat] Copy constructor called." << endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	cout << "[WrongCat] Destructor called for " << type << "." << endl;
}

void WrongCat::makeSound() const
{
	cout << "Cats don't bark." << endl;
}

string WrongCat::getType() const
{
	return (type);
}