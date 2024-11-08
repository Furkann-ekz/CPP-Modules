#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	w;
		std::string	name;
	public:
		HumanA();
		HumanA(std::string name);
		attack();
};

#endif