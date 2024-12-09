#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	a;
	ClapTrap	b("b");
	ClapTrap	c;
	ClapTrap	d(b);

	FragTrap	f;
	FragTrap	g("g");
	FragTrap	h;
	FragTrap	j(f);

	c = b;
	h = g;

	a.attack("b");
	b.takeDamage(30);
	c.beRepaired(10);
	a.beAttack(a,b);

	f.attack("h");
	f.beAttack(f,h);
	g.beRepaired(10);
	h.takeDamage(30);
}