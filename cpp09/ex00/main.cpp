#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.processInput(argv[1]);
	return 0;
}