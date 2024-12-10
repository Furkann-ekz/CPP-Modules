#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
		FragTrap	f;
		FragTrap	g("g");
		FragTrap	h;
		FragTrap	j(f);

		h = g;

		f.beAttack(f,h);
		g.beRepaired(10);
	}
	{
		ScavTrap	w;
		ScavTrap	x("x");
		ScavTrap	y;
		ScavTrap	z(w);

		y = x;

		w.beAttack(w,x);
		x.beRepaired(10);
	}
}