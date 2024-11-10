#include "HumanB.hpp"

HumanB::HumanB(string n)
{
	name = n;
}

HumanB::HumanB(string n, Weapon &w)
{
	name = n;
	weapon = &w;
}

void	HumanB::attack()
{
	cout << name << " attacks with their " << weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}
