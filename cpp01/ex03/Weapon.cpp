#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "";
}

Weapon::Weapon(string w)
{
	type = w;
}

void	Weapon::setType(string w)
{
	type = w;
}

const string& Weapon::getType()
{
	return (type);
}
