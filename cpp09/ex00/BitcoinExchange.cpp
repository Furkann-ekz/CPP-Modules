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

std::string BitcoinExchange::getDate(std::string s)
{
	std::string date, syear, smonth, sday, temp;
	std::stringstream ss(s);
	int year, month, day;
	std::getline(ss, date, ' ');
	
	ss.clear();
	ss.str("");
	ss.str(s);
	
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

	if (year < 2009)
		return ("2009-01-02");
	if (year == 2009 && month == 1 && day < 2)
		return ("2009-01-02");
	if (year > 2022)
		return ("2022-03-29");
	if (year == 2022 && month > 3)
		return ("2022-03-29");
	if (year == 2022 && month == 3 && day > 29)
		return ("2022-03-29");
	return (date);
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
	std::string *listString = new std::string[i];
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
		std::stringstream s(line);
		listString[++j] = s.str();
	}
	std::string date;
	j = -1;
	while (++j < i)
	{
		date = getDate(listString[j]);
		if (!(exchangeRates.count(date) > 0))
			date = findDate(date);
		cout << date << " | " << exchangeRates[date] << endl;
	}
	delete[] data_csv;
	delete[] listString;
}

std::string BitcoinExchange::findDate(std::string date)
{
	int i = -1;
	std::stringstream s(date);
	int year, month, day;
	char temp;
	s >> year >> temp >> month >> temp >> day;
	// cout << year << temp << month << temp << day << endl;
	while (++i < 1612)
	{
		s.clear();
		s.str("");
		s.str(data_csv[i]);
		int y, m, d;
		s >> y >> temp >> m >> temp >> d;
		if (y == year && month == m && d > day)
		{
			date = data_csv[i - 1];
			break ;
		}
	}
	return (date);
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

bool BitcoinExchange::beLoadData_csv(const std::string &f)
{
	data_csv = new std::string[1612];
	std::ifstream file(f.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	int i = 0;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		
		std::getline(ss, date, ',');
		data_csv[i] = date;
		if (ss.fail())
		continue;
		i++;
	}
	file.close();
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

		if (ss.fail() || !isValidDate(date))
			continue;
		exchangeRates[date] = rate;
	}
	file.close();
	if (beLoadData_csv(f) == false)
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}
}