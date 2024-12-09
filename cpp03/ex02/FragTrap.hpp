#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "iostream"
# include "ClapTrap.hpp"
# include "FragTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(string n);
		FragTrap(FragTrap const &src);
		FragTrap &operator=(FragTrap const &src);
		~FragTrap();
		void attack(const string &target);
		void highFivesGuys(void);
};

#endif