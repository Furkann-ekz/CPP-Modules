#include "Zombie.hpp"

int	main()
{
	Zombie *z = zombieHorde(5, "test");

	int i = -1;
	while (++i < 5)
		z[i].announce();
	i = -1;
	delete[] z;
}
