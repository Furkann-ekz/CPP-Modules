#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>

using std::string;
using std::endl;
using std::cout;
using std::string;

class Scalar
{
	private:
		static bool isChar(const string &literal);
		static bool isInt(const string &literal);
		static bool isFloat(const string &literal);
		static bool isDouble(const string &literal);

		static void printConversions(char value);
		static void printConversions(int value);
		static void printConversions(float value);
		static void printConversions(double value);
	public:
		Scalar();
		Scalar(const Scalar &other);
		Scalar &operator=(const Scalar &other);
		~Scalar();

		static void convert(const string &literal);


};

#endif