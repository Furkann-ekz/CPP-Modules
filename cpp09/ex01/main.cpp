#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.calculate(av[1]);
	return 0;
}