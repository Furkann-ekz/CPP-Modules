#ifndef HARL_HPP
# define HARL_HPP

# include "iostream"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		typedef void (Harl::*fpoint)(void);
	public:
		void complain(string level);
};

#endif