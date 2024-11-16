#include "Zombie.hpp"

Zombie*	zombieHorde(int N, string name)
{
	int		i;
	Zombie	*z;

	i = -1;
	if (N <= 0)
		return (NULL);

	z = new Zombie[N];
	while (++i < N)
		z[i].setName(name);
	return (z);
}
