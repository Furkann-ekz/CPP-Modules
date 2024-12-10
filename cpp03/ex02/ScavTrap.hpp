#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "iostream"
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	guarding_gate;
	public:
		ScavTrap();
		ScavTrap(string n);
		ScavTrap(ScavTrap const &src);
		ScavTrap &operator=(ScavTrap const &src);
		~ScavTrap();
		void	attack(const string &target);
		void	beAttack(ScavTrap &attacker, ScavTrap &defender);
		void	guardGate();
};

#endif