#include "BitcoinExchange.hpp"
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		exchangeRates = other.exchangeRates;
	return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

	int year, month, day;
	std::stringstream ss(date);
	char dash;
	ss >> year >> dash >> month >> dash >> day;

	if (ss.fail() || !ss.eof()) return false;
	if (month < 1 || month > 12 || day < 1 || day > 31) return false;
	return true;
}

bool BitcoinExchange::isValidValue(float value) const
{
	return value >= 0 && value <= 1000;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		float rate;

		std::getline(ss, date, ',');
		ss >> rate;

		if (ss.fail() || !isValidDate(date))
			continue;
		exchangeRates[date] = rate;
	}
	file.close();
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
	if (it == exchangeRates.begin() && it->first > date)
		return "";
	if (it == exchangeRates.end() || it->first > date)
		--it;
	return it->first;
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, sep;
		float value;

		std::getline(ss, date, ' ');
		ss >> sep >> value;

		if (sep != "|" || !isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidValue(value))
		{
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else
				std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::string closestDate = findClosestDate(date);
		if (closestDate.empty())
		{
			std::cout << "Error: no valid date in database before " << date << std::endl;
			continue;
		}

		float rate = exchangeRates[closestDate];
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	file.close();
}