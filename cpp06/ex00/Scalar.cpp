#include "Scalar.hpp"

Scalar::Scalar() {}

Scalar::Scalar(const Scalar &other)
{
	(void)other;
}

Scalar &Scalar::operator=(const Scalar &other)
{
	(void)other;
	return *this;
}

Scalar::~Scalar() {}

void Scalar::convert(const string &literal)
{
	if (isChar(literal))
	{
		char value = literal[0];
		printConversions(value);
	}
	else if (isInt(literal))
	{
		int value = std::atoi(literal.c_str());
		printConversions(value);
	}
	else if (isFloat(literal))
	{
		float value = std::strtof(literal.c_str(), NULL);
		printConversions(value);
	}
	else if (isDouble(literal))
	{
		double value = std::strtod(literal.c_str(), NULL);
		printConversions(value);
	}
	else
		cout << "Conversion is impossible" << endl;
}

bool Scalar::isChar(const string &literal)
{
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool Scalar::isInt(const string &literal)
{
	char *end;
	std::strtol(literal.c_str(), &end, 10);
	return *end == '\0';
}

bool Scalar::isFloat(const string &literal)
{
	char *end;
	std::strtof(literal.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0';
}

bool Scalar::isDouble(const string &literal)
{
	char *end;
	std::strtod(literal.c_str(), &end);
	return *end == '\0';
}

void Scalar::printConversions(char value)
{
	cout << "char: '" << value << "'" << endl;
	cout << "int: " << static_cast<int>(value) << endl;
	cout << "float: " << static_cast<float>(value);
	if (static_cast<int>(value) % 1 == 0)
		cout << ".0" << "f" << endl;
	cout << "double: " << static_cast<double>(value);
	if (static_cast<int>(value) % 1 == 0)
		cout << ".0" << endl;
}

void Scalar::printConversions(int value)
{
	if (value < 0 || value > 127 || !std::isprint(value))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: '" << static_cast<char>(value) << "'" << endl;
	cout << "int: " << value << endl;
	cout << "float: " << static_cast<float>(value);
	if (static_cast<int>(value) % 1 == 0)
		cout << ".0" << "f" << endl;
	cout << "double: " << static_cast<double>(value);
	if (static_cast<int>(value) % 1 == 0)
		cout << ".0" << endl;
}

void Scalar::printConversions(float value)
{
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
		cout << "char: Unprintable" << endl;
	else
		cout << "char: '" << static_cast<char>(value) << "'" << endl;
	cout << "int: " << static_cast<int>(value) << endl;
	cout << "float: " << value;
	if (fmod(value, 1.0) == 0.0)
		cout << ".0";
	cout << "f" << endl;
	cout << "double: " << static_cast<double>(value);
	if (fmod(value, 1.0) == 0.0)
		cout << ".0" << endl;
	else
		cout << endl;
}

void Scalar::printConversions(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
		cout << "char: Unprintable" << endl;
	else
		cout << "char: '" << static_cast<char>(value) << "'" << endl;
	cout << "int: " << static_cast<int>(value) << endl;
	cout << "float: " << static_cast<float>(value);
	if (fmod(value, 1.0) == 0.0)
		cout << ".0";
	cout << "f" << endl;
	cout << "double: " << value;
	if (fmod(value, 1.0) == 0.0)
		cout << ".0" << endl;
	else
		cout << endl;
}