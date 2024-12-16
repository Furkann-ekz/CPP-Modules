#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	cout << "[Animal] Default constructor called." << endl;
}

Animal::Animal(string typ)
{
	type = typ;
	cout << "[Animal] Constructor called." << endl;
}

Animal::Animal(Animal const &src)
{
	if (this != &src)
		*this = src;
	cout << "[Animal] Copy constructor called." << endl;
}

Animal &Animal::operator=(Animal const &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

Animal::~Animal()
{
	cout << "[Animal] Destructor called for " << type << "." << endl;
}

void Animal::makeSound() const
{
	cout << "This is a generic animal sound." << endl;
}

string Animal::getType() const
{
	return (type);
}