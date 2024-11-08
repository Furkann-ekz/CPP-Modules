#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*z;

	i = -1;
	if (N <= 0)
		return (NULL);

	z = new Zombie[N];
	while (++i < N)
		z[i] = Zombie(name);
	return (z);
}
