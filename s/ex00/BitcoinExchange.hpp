#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using std::cout;
using std::endl;

class BitcoinExchange
{
	private:
		std::map<std::string, float> exchangeRates;
		std::string *data_csv;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadData(const std::string &f);
		bool isValidDate(std::string string);
		void start(char *av);
		bool isValidValue(float value);
		std::string getDate(std::string s);
		bool beLoadData_csv(const std::string &f);
};

#endif