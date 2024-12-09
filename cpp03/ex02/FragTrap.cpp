#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	health = 100;
	energy = 100;
	damage = 30;
	cout << "FragTrap default constructor called." << endl;
}

FragTrap::FragTrap(string n) : ClapTrap(n)
{
	health = 100;
	energy = 100;
	damage = 30;
	cout << "FragTrap constructor called for " << name << "." << endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	cout << "FragTrap copy constructor called." << endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
	cout << "FragTrap assignement operator called" << endl;
	if (this != &src)
	{
		energy = src.energy;
		name = src.name;
		damage = src.damage;
		health = src.health;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	cout << "FragTrap " << this->name << " destructor called" << endl;
}

void FragTrap::highFivesGuys(void)
{
	cout << "FragTrap " << name << ": You want a high five? Here you go." << endl; 
}

void FragTrap::attack(const std::string& target)
{
	if (health == 0)
	{
		cout << "FragTrap " << name << " can't attack because he/she is dead." << endl;
		return;
	}
	if (energy == 0)
	{
		cout << "FragTrap " << name << " can't attack because he/she has no energy." << endl;
		return;
	}
	cout << "FragTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << endl;
	energy--;
}
