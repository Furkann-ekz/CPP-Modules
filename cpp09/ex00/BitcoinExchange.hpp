#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> exchangeRates;

		bool isValidDate(const std::string& date) const;
		bool isValidValue(float value) const;
		std::string findClosestDate(const std::string& date) const;
		void loadDatabase(const std::string& filename);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void processInput(const std::string& filename);
};

#endif