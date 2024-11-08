#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "iostream"

class Zombie
{
	private:
		string	name;

	public:
		Zombie();
		Zombie(std::string zname);
		void announce(void);
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif