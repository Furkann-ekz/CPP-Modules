#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon	*weapon;
		string	name;
	public:
		HumanB(string n);
		HumanB(string n, Weapon &w);
		void attack();
		void setWeapon(Weapon &w);
};

#endif