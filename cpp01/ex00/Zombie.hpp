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
		void	announce(void);
		~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif