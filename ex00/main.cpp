#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: You must be add your list." << endl;
		return 1;
	}
	std::ifstream file("data.csv");
	if (!file.is_open())
		return (std::cerr << "Error: No database file." << endl, -1);
	BitcoinExchange btc;
	btc.start(av[1]);
}