#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	cout << "[Dog] Default constructor called." << endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	if (this != &src)
		*this = src;
	cout << "[Dog] Copy constructor called." << endl;
}

Dog::Dog(string typ)
{
	type = typ;
	brain = new Brain();
	cout << "[Dog] Constructor called." << endl;
}

Dog &Dog::operator=(Dog const &src)
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

Dog::~Dog()
{
	if (brain)
		delete brain;
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

void Dog::setBrainIdea(int index, string const idea)
{
	brain->setIdea(index, idea);
}

string Dog::getBrainIdea(int index) const
{
	return (brain->getIdea(index));
}