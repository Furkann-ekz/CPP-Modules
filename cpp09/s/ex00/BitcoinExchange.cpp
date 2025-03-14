#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadData("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : exchangeRates(other.exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
	return *this;
}

void BitcoinExchange::start(char **av) {}

bool BitcoinExchange::isValidDate(std::string *string)
{
	int lenght;
	int k = 0;
	std::string &s = string[k];
	int i = 0;
	lenght = s.length();
	int x = 0;
	while (x < 1612)
	{
		while (k < lenght)
		{
			
			char c = 
			k++;
		}
	}
	return true;
}

void BitcoinExchange::loadData(const std::string &f)
{
	std::ifstream file(f.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: wrong file name or access denied." << endl;
		return ;
	}
	std::string line;
	int i = 1000;
	std::string *splitLine = new std::string[1612];
	std::getline(file, line);
	int j = 0;
	while (std::getline(file, line) && j < 1612)
	{
		std::stringstream s;
		s << i++ << '-' << line;
		splitLine[j] = s.str();
		j++;
	}
	file.close();
	isValidDate(splitLine);

	// int x = -1;
	// while (++x < j)
	// 	cout << splitLine[x] << endl;
	// cout << splitLine[0] << endl;
	delete[] splitLine;
}