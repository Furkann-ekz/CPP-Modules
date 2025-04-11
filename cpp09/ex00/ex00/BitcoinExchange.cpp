#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadData("data.csv");
	value = 0;
}

BitcoinExchange::~BitcoinExchange()
{
	if (data_csv)
		delete[] data_csv;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : exchangeRates(other.exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		exchangeRates = other.exchangeRates;
	}
	return *this;
}

std::string BitcoinExchange::getDate(std::string s)
{
	std::stringstream ss(s);
	std::string date;
	std::getline(ss, date, ' ');

	return (date);
}

bool valueControl(std::string val)
{
	size_t i = -1;
	if (val[0] == '-')
		return (std::cerr << "Error: not a positive number: " << val << endl, false);
	while (++i < val.length())
	{
		if (i >= 4 && val[0] != '1' && val[1] != '0' && val[2] != '0' && val[3] != '0')
			return (std::cerr << "Error: too large number: " << val << endl, false);
		if (!(val[i] <= '9' && val[i] >= '0'))
			return (std::cerr << "Error: not a number or not an integer: " << val << endl, false);
	}
	return true;
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
		delete[] listString;
		return ;
	}

	int j = 0;
	while (std::getline(file, line) && j < i)
	{
		std::stringstream s(line);
		listString[j] = s.str();
		j++;
	}

	std::string date;
	std::string val;
	bool control;
	j = 0;
	while (++j < i)
	{
		std::stringstream v(listString[j]);
		std::getline(v, date, '|');
		control = true;
		v >> val;
		if (valueControl(val) == false)
		{
			control = false;
			continue;
		}
		if (control)
		{
			v.clear();
			v.str("");
			v.str(val);
			v >> value;
		}
		date = getDate(listString[j]);
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << endl;
			continue;
		}
		if (!(exchangeRates.count(date) > 0))
			date = findDate(date);
		if (invalidDate(date))
			continue;
		long long result = exchangeRates[date] * value;
		if (result < 0 || result > 2147483647)
			result = 2147483647;
		cout << date << " => " << value << " = " << result << endl;
	}

	file.close();
	delete[] listString;
}

bool BitcoinExchange::invalidDate(std::string &date)
{
	std::stringstream s(date);
	int year, month, day;
	char temp;
	s >> year >> temp >> month >> temp >> day;

	std::string closest_date = "2009-01-02";
	bool found = false;

	for (int i = 0; i < 1612; ++i)
	{
		std::stringstream ss(data_csv[i]);
		int y, m, d;
		ss >> y >> temp >> m >> temp >> d;

		if ((y < year) || 
			(y == year && m < month) || 
			(y == year && m == month && d < day))
		{
			closest_date = data_csv[i];
			found = true;
		}
		else if (y > year || (y == year && m > month) || (y == year && m == month && d >= day))
			break;
	}

	if (!found)
		return true;
	return false;
}

std::string BitcoinExchange::findDate(std::string date)
{
	std::stringstream s(date);
	int year, month, day;
	char temp;
	s >> year >> temp >> month >> temp >> day;

	std::string closest_date = "2009-01-02";
	bool found = false;

	for (int i = 0; i < 1612; ++i)
	{
		std::stringstream ss(data_csv[i]);
		int y, m, d;
		ss >> y >> temp >> m >> temp >> d;

		if ((y < year) || 
			(y == year && m < month) || 
			(y == year && m == month && d < day))
		{
			closest_date = data_csv[i];
			found = true;
		}
		else if (y > year || (y == year && m > month) || (y == year && m == month && d >= day))
			break;
	}

	if (!found)
	{
		std::cerr << "Error: No earlier date found for " << date << endl;
		return closest_date;
	}
	return closest_date;
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
		std::cerr << "Error: could not open database file." << endl;
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
		std::cerr << "Error: could not open database file." << endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		int rate;

		std::getline(ss, date, ',');
		ss >> rate;

		if (ss.fail() || !isValidDate(date))
			continue;
		exchangeRates[date] = rate;
	}
	file.close();
	if (beLoadData_csv(f) == false)
	{
		std::cerr << "Error: could not open database file." << endl;
		return;
	}
}