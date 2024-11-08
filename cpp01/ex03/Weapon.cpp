#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "";
}

Weapon::Weapon(std::string w)
{
	type = w;
}

Weapon::setType(std::string w)
{
	type = w;
}

const std::string& Weapon::getType()
{
	return (type);
}
