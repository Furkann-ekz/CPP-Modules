#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"

using	std::cout;
using	std::string;
using	std::endl;

class WrongAnimal
{
	protected:
		string type;
	public:
		WrongAnimal();
		WrongAnimal(string typ);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal &operator=(WrongAnimal const &src);
		~WrongAnimal();
		void makeSound() const;
		string getType() const;
};

#endif