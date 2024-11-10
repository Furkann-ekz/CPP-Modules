#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(string zname)
{
	name = zname;
}

void	Zombie::announce(void)
{
	cout << name << " BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie()
{
	cout << name << " has been destroyed." << endl;
}
