#ifndef  PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include "Contact.hpp"
# include <cstdlib>

class	PhoneBook
{
	private:
		Contact	conts[8];
		int		id;
		int		max;

	public:
		PhoneBook();
		void	add(void);
		void	search(void);
};

#endif