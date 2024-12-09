#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a;
	ClapTrap	b("b");
	ClapTrap	c;
	c = b;
	a.attack("b");
	a.beAttack(a,b);
	c.beRepaired(10);
}