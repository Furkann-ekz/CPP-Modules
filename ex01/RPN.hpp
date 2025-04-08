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
		std::list<char> ops;
		std::list<char> controler;
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		bool getList(const std::string &expression);
		void calculate(const std::string &av);
};

#endif