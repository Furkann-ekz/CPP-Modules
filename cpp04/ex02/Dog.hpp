#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(string typ);
		Dog(Dog const &src);
		Dog &operator=(Dog const &src);
		~Dog();
		void makeSound() const;
		string getType() const;
		void setBrainIdea(int index, string const idea);
		string getBrainIdea(int index) const;
};

#endif 