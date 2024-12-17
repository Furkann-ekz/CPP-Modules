#include "Brain.hpp"

Brain::Brain()
{
	cout << "[Brain] Default constructor called." << endl;
}

Brain::Brain(Brain const &src)
{
	if (this != &src)
		*this = src;
	cout << "[Brain] Copy constructor called." << endl;
}

Brain &Brain::operator=(Brain const &src)
{
	if (this != &src)
		 for (int i = 0; i < 100; i++)
            ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	cout << "[Brain] Destructor called." << endl;
}

void Brain::setIdea(int index, string const idea)
{
	if (index >= 100 || index < 0)
		return ;
	ideas[index] = idea;
}

string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (ideas[index]);
	return ("Invalid index number.");
}
