#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <list>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

class RPN
{
	private:
		std::list<char> arg;
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		bool getList(const std::string &expression);
		void calculate(const std::string &av);
		bool argControl(void);
};

#endif