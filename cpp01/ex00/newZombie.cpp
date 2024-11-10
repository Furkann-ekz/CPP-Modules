#include "Zombie.hpp"

Zombie	*newZombie(string name)
{
	Zombie* z = new Zombie(name);
	return z;
}
