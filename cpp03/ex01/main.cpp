#include "ScavTrap.hpp"

int main()
{
	{
		ClapTrap	a;
		ClapTrap	b("b");
		ClapTrap	c;
		ClapTrap	d(b);
		
		c = b;

		a.beAttack(a,b);
		c.beRepaired(10);
	}
	{
		ScavTrap	x;
		ScavTrap	y("y");
		ScavTrap	z;
		ScavTrap	w(y);

		z = x;

		x.beAttack(x,y);
		z.beRepaired(10);
		y.guardGate();
	}
}