#include "Zombie.hpp"

int main()
{
	Zombie	*z;

	z = newZombie("Zombie in the heap");
	z->announce();
	delete z;

	randomChump("Zombie in the stack");
}
