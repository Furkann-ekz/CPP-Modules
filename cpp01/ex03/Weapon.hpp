#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "iostream"

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(std::string w);
		setType(std::string w);
		const std::string&	Weapon::getType();
};

#endif