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

std::string getDate(std::string *s, int lines)
{
	int j = 0;
	while (j < lines)
	{
		std::string &line = s[j];
		int x = 0;
		int length = line.length();
		while (x < length)
		{
			std::string date;
			std::stringstream ss(line);
			std::string temp, syear, smonth, sday;
			int year, month, day;
			float rate;

			std::getline(ss, date, ' ');
			ss >> rate;
			ss.clear();
			ss.str("");
			ss.str(date);

			std::getline(ss, syear, '-');
			std::getline(ss, smonth, '-');
			std::getline(ss, sday, ' ');
			
			ss.clear();
			ss.str("");
			ss.str(syear);
			ss >> year;

			ss.clear();
			ss.str("");
			ss.str(smonth);
			ss >> month;

			ss.clear();
			ss.str("");
			ss.str(sday);
			ss >> day;

			if (year < 2009 && month < 1 && day < 2)
			{
				cout << "test" << endl << endl;
				return ("2009-01-02");
			}
			else if (line[x] == '-' && x > 4)
				return ("2022-03-29");
			x++;
		}
	}
	return ("test");
}

void BitcoinExchange::start(char *av)
{
	std::ifstream file(av);
	if (!file.is_open())
	{
		std::cerr << "Error: file cannot be opened." << endl;
		return ;
	}
	std::string line;
	int i = 0;
	while (std::getline(file, line))
		i++;
	std::string *splitString = new std::string[i];
	file.close();
	file.open(av);
	if (!file.is_open())
	{
		std::cerr << "Error: file cannot be opened." << endl;
		return ;
	}
	int j = -1;
	while (std::getline(file, line) && j < i)
	{
		std::stringstream s;
		s << line;
		splitString[++j] = s.str();
	}
	std::string date;
	j = -1;
	while (++j < i)
	{
		date = getDate(splitString, i);
	}
}

bool characterControl(char c)
{
	int i = -1;
	std::string s = "0123456789|-. ";
	while (++i < 15)
		if (c == s[i])
			return true;
	return false;
}

bool BitcoinExchange::isValidValue(float value)
{
	return value >= 0 && value <= 1000;
}

bool BitcoinExchange::isValidDate(std::string string)
{
	if (string.length() < 10 || string[4] != '-' || string[7] != '-')
		return (false);

	int year, month, day;
	std::stringstream s(string);
	char dash;
	s >> year >> dash >> month >> dash >> day;
	if (s.fail())
		return false;
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

void BitcoinExchange::loadData(const std::string &f)
{
	std::ifstream file(f.c_str());
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

		cout << date << endl;
		if (ss.fail() || !isValidDate(date))
			continue;
		exchangeRates[date] = rate;
	}
	file.close();
}