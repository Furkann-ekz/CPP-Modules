#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "iostream"

using	std::cout;
using	std::endl;
using	std::string;

class Animal
{
	protected:
		string	type;
	public:
		Animal();
		Animal(string typ);
		Animal(Animal const &src);
		Animal &operator=(Animal const &src);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		virtual string getType() const;
};

#endif