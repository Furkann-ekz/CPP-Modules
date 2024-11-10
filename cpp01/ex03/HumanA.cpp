#include "HumanA.hpp"

HumanA::HumanA(string n, Weapon &w) : weapon(w)
{
	name = n;
}

void	HumanA::attack()
{
	cout << name << " attacks with their " << weapon.getType() << endl;
}
