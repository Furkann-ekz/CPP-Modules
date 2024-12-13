#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "unnamed";
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
	cout << "ClapTrap copy constructor called." << endl;
	name = src.name;
	health = src.health;
	energy = src.energy;
	damage = src.damage;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	cout << "ClapTrap assignment operator called" << endl;
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
	if (health == 0)
	{
		cout << "ClapTrap " << name << "'s hit points are 0. He/She is dead." << endl;
		return ;
	}
	else if (energy == 0)
	{
		cout << "ClapTrap " << name << " can't attack because it has no energy." << endl;
		return ;
	}
	cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << endl;
	energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (health == 0)
	{
		cout << "ClapTrap " << name << " is already dead." << endl;
		return ;
	}
	else if (health > amount)
		health -= amount;
	else
		health = 0;
	cout << "ClapTrap " << name << " was attacked and lost " << amount << " hit points. Current hit points: " << health << "." << endl;
}

void	ClapTrap::beAttack(ClapTrap &attacker, ClapTrap &defender)
{
	attacker.attack(defender.name);
	defender.takeDamage(attacker.damage);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health == 0)
	{
		cout << "ClapTrap " << name << " can't be repaired because he/she is dead." << endl;
		return;
	}
	if (energy == 0)
	{
		cout << "ClapTrap " << name << " can't be repaired because energy points are 0." << endl;
		return;
	}
	health += amount;
	energy--;
	cout << "ClapTrap " << name << " repaired and gained " << amount 
		 << " hit points. Current hit points: " << health << "." << endl;
}
