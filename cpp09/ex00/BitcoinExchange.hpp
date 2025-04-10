#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>

using std::cout;
using std::endl;

class BitcoinExchange
{
	private:
		std::map<std::string, float> exchangeRates;
		std::string *data_csv;
		float value;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadData(const std::string &f);
		bool isValidDate(std::string string);
		void start(char *av);
		std::string getDate(std::string s);
		bool beLoadData_csv(const std::string &f);
		std::string findDate(std::string date);
		bool invalidDate(std::string &date);
};

#endif