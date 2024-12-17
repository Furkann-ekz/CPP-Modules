#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(string typ);
		Cat(Cat const &src);
		Cat &operator=(Cat const &src);
		void setBrainIdea(int index, string const idea);
		~Cat();
		void makeSound() const;
		string getType() const;
		string getBrainIdea(int index) const;
};

#endif