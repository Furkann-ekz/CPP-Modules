#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(string typ);
		Dog(Dog const &src);
		Dog &operator=(Dog const &src);
		~Dog();
		void makeSound() const;
		string getType() const;
};

#endif