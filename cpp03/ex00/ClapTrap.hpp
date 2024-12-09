#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "iostream"

using	std::string;
using	std::cout;
using	std::endl;

class ClapTrap
{
	private:
		string			name;
		unsigned int	health;
		unsigned int	energy;
		unsigned int	damage;
	public:
		ClapTrap();
		ClapTrap(string n);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=(ClapTrap const &src);
		~ClapTrap();
		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	beAttack(ClapTrap const &attacker, ClapTrap &defender);
};

#endif