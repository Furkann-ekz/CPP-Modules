#include "ScavTrap.hpp"

int main()
{
	ClapTrap	a;
	ClapTrap	b("b");
	ClapTrap	c;
	ClapTrap	d(b);

	ScavTrap	x;
	ScavTrap	y("y");
	ScavTrap	z;
	ScavTrap	w(y);

	z = x;

	c = b;

	a.attack("b");
	a.beAttack(a,b);
	c.beRepaired(10);
	d.takeDamage(5);

	x.attack("y");
	z.beRepaired(10);
	x.beAttack(x,y);
	y.guardGate();
}