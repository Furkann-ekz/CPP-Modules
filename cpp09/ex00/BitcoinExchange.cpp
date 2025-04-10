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
	size_t i = 0;
	cout << val << endl;
	if (val[0] == '-')
		return (std::cerr << "Error: not a positive number." << endl, false);
	else if (val[0] == '0' && val[1] != '.')
		return (std::cerr << "Error: 0 is invalid value." << endl, false);
	else if (val[0] == '0' && val[1] == '.')
	{
		size_t i = 2;
		while (val[i] == '0')
			i++;
		if (i > 9)
			return (std::cerr << "Error: DO YOU THINK THIS IS A FLOAT NUMBER?!" << endl, false);
		if (val[i] && !(val[i] > '0' && val[i] <= '9'))
			return (std::cerr << "Error: invalid value." << endl, false);
		else if (!val[i])
			return (std::cerr << "Error: 0 is invalid value." << endl, false);
	}
	
	bool decimal = false;
	for (size_t i = 0; i < val.length(); ++i)
	{
		if (val[i] == '.') 
		{
			if (decimal)
				return (std::cerr << "Error: invalid value." << endl, false);
			decimal = true;
		}
		else if (!isdigit(val[i]))
			return (std::cerr << "Error: invalid value." << endl, false);
	}

	if (val[0] == '1'
		&& val[1] && val[1] == '0'
		&& val[2] && val[2] == '0'
		&& val[3] && val[3] == '0')
	{
		i = 4;
		if (val[i] == '.')
		{
			i++;
			while (val[i] == '0')
				i++;
			if (i > 11)
				return (std::cerr << "Error: ARE YOU SERIOUS? DO YOU THINK THIS IS A RELIABLE FLOAT NUMBER?!" << endl, false);
			if (!val[i])
			{
				if (val[i - 1] == '0')
					return true;
			}
			else if (val[i] && val[i] > '0')
				return (std::cerr << "Error: too large number." << endl, false);
		}
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
	float valu = 0.0f;
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
			v >> valu;
			value = valu;
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
		float result = exchangeRates[date] * value;
		if (result < 0.0f || static_cast<long double>(result) > 2147483647.0f)
			result = 2147483647.0f;
		std::cout << std::fixed << std::setprecision(7);
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

bool characterControl(char c)
{
	int i = -1;
	std::string s = "0123456789|-. ";
	while (++i < 15)
		if (c == s[i])
			return true;
	return false;
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
		std::cerr << "Error: could not open database file." << endl;
		return;
	}
}