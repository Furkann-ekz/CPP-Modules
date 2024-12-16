#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(string typ);
		WrongCat(WrongCat const &src);
		WrongCat &operator=(WrongCat const &src);
		~WrongCat();
		void makeSound() const;
		string getType() const;
};

#endif