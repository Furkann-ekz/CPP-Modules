#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	health = 100;
	energy = 50;
	damage = 20;
	guarding_gate = false;
	cout << "ScavTrap default constructor called." << endl;
}

ScavTrap::ScavTrap(string n) : ClapTrap(n)
{
	health = 100;
	energy = 50;
	damage = 20;
	cout << "ScavTrap constructor called for " << name << "." << endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	cout << "ScavTrap copy constructor called." << endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	cout << "ScavTrap assignement operator called" << endl;
	if (this != &src)
	{
		energy = src.energy;
		name = src.name;
		damage = src.damage;
		health = src.health;
		guarding_gate = src.guarding_gate;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap " << this->name << " destructor called" << endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (health == 0)
	{
		cout << "ScavTrap " << name << " can't attack because he/she is dead." << endl;
		return;
	}
	if (energy == 0)
	{
		cout << "ScavTrap " << name << " can't attack because he/she has no energy." << endl;
		return;
	}
	cout << "ScavTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << endl;
	energy--;
}

void	ScavTrap::beAttack(ScavTrap &attacker, ScavTrap &defender)
{
	attacker.attack(defender.name);
	defender.takeDamage(attacker.damage);
}


void ScavTrap::guardGate()
{
	if (!guarding_gate)
	{
		guarding_gate = true;
		cout << "ScavTrap " << name << " is now guarding the gate." << endl;
	}
	else
		cout << "ScavTrap " << name << " is already guarding the gate." << endl;
}
