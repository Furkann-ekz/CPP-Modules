#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "unnamed ClapTrap";
	health = 10;
	energy = 10;
	damage = 0;
	cout << "ClapTrap default constructor called." << endl;
}

ClapTrap::ClapTrap(string n)
{
	name = n;
	health = 10;
	energy = 10;
	damage = 0;
	cout << "ClapTrap constructor called for " << name << "." << endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	cout << "ClapTrap coppy constructor called." << endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	cout << "ClapTrap assignement operator called" << endl;
	if (this != &src)
	{
		energy = src.energy;
		name = src.name;
		damage = src.damage;
		health = src.health;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap " << this->name << " destructor called" << endl;
}

void	ClapTrap::attack(const string &target)
{
	if (health > 0 && energy > 0)
	{
		cout << "ClapTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << endl;
		energy--;
	}
	else if (energy == 0)
		cout << "ClapTrap " << name << " can't doing attack, because he/she hasn't energy." << endl;
	else
		cout << "ClapTrap " << name << "'s hit points 0. He/She is dead." << endl; 
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (health > amount)
		health -= amount;
	else
	{
		cout << "ClapTrap " << name << " is already dead." << endl;
		return ;
	}
	cout << "ClapTrap " << name << " was attacked and lost " << amount << "hit points, his current hit point is " << health << ".";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy > 0 && health > 0)
	{
		health += amount;
		energy--;
		cout << "ClapTrap " << name << " repaired his health and gained " << amount << " hit points. His new hit points are " << health << endl;
	}
	else if (energy == 0)
		cout << "ClapTrap " << name << " can't be repaired because energy points 0." << endl;
	else if (health == 0)
		cout << "ClapTrap " << name << " can't be repaired because she/he is dead." << endl;
}
