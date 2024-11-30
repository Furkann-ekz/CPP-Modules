#include "HumanB.hpp"

HumanB::HumanB(string n)
{
	name = n;
	weapon = NULL;
}

HumanB::HumanB(string n, Weapon &w)
{
	name = n;
	weapon = &w;
}

void	HumanB::attack()
{
	if (!weapon)
		cout << name << " can't attack when you don't have a weapon " << endl;
	else
		cout << name << " attacks with their " << weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}
