#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon	&weapon;
		string	name;
	public:
		HumanA(string n, Weapon &w);
		void attack();
};

#endif