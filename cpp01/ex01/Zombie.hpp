#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "iostream"

using std::string;
using std::cout;
using std::endl;

class Zombie
{
	private:
		string	name;

	public:
		Zombie();
		Zombie(string zname);
		void announce(void);
		~Zombie();
};

Zombie*	zombieHorde(int N, string name);

#endif