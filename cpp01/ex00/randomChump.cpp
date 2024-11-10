#include "Zombie.hpp"

void randomChump(string name)
{
	Zombie z = Zombie(name);

	z.announce();
}