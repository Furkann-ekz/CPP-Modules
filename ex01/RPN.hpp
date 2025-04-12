#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>

using std::cout;
using std::endl;

class RPN
{
	private:
		std::list<int> stack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void calculate(const std::string &expression);
};

#endif