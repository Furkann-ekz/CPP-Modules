#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a;
	ClapTrap	b("b");
	ClapTrap	c;
	c = b;
	a.attack("b");
	b.takeDamage(10);
	c.beRepaired(10);
}