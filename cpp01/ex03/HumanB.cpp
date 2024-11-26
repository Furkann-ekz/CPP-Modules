#include "HumanB.hpp"

HumanB::HumanB(string n)
{
	name = n;
	weapon = nullptr;
}

HumanB::HumanB(string n, Weapon &w)
{
	name = n;
	weapon = &w;
}

void	HumanB::attack()
{
	if (!weapon)
		cout << name << " attacks with their hands " << endl;
	else
		cout << name << " attacks with their " << weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}
