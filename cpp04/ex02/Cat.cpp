#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
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
	brain = new Brain();
	cout << "[Cat] Constructor called." << endl;
}

Cat &Cat::operator=(Cat const &src)
{
	if (this != &src)
	{
		if (brain)
			delete brain;
		type = src.type;
		brain = new Brain(*src.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	if (brain)
		delete brain;
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

void Cat::setBrainIdea(int index, string const idea)
{
	brain->setIdea(index, idea);
}

string Cat::getBrainIdea(int index) const
{
	return (brain->getIdea(index));
}