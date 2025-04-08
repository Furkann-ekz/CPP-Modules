#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Error: you must be add your list." << endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.start(av[1]);
}