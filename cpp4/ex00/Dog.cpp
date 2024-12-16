#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	cout << "[Dog] Default constructor called." << endl;
}

Dog::Dog(string typ)
{
	type = typ;
	cout << "[Dog] Constructor called." << endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	if (this != &src)
		*this = src;
	cout << "[Dog] Copy constructor called." << endl;
}

Dog &Dog::operator=(Dog const &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

Dog::~Dog()
{
	cout << "[Dog] Destructor called for " << type << "." << endl;
}

void Dog::makeSound() const
{
	cout << "Woof!" << endl;
}

string Dog::getType() const
{
	return (type);
}