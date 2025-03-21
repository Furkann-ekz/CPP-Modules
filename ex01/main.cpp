#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Bad using. Example: ./RPN '3 6 +' " << endl;
		return 1;
	}
	RPN rpn;
	rpn.calculate(av[1]);
	return 0;
}
// 3    4 + 5 -   \t   * 0