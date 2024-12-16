#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	cout << "[Cat] Default constructor called." << endl;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	if (this != &src)
		*this = src;
	cout << "[Cat] Copy constructor called." << endl;
}

Cat::Cat(string typ)
{
	type = typ;
	cout << "[Cat] Constructor called." << endl;
}

Cat &Cat::operator=(Cat const &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

Cat::~Cat()
{
	cout << "[Cat] Destructor called for " << type << "." << endl;
}

void Cat::makeSound() const
{
	cout << "Meow!" << endl;
}

string Cat::getType() const
{
	return (type);
}