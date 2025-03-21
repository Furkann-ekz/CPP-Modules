#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other): string(other.string) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		string = other.string;
	return *this;
}

RPN::~RPN() {}

bool operatorControl(const char c)
{
	std::string operators = "-+*/";
	size_t i = -1;
	bool control = false;
	while (i < operators.length())
		if (operators[i] == c)
			control = true;
	if (control == true)
		return true;
	return false;
}

bool RPN::getList(const std::string &expression)
{
	size_t i = 0;
	while (i < expression.length())
	{
		while (isspace(expression[i]))
			i++;
		if ((isdigit(expression[i]) && expression[i] >= '0' && expression[i] <= '9') || operatorControl(expression[i]))
		{
			char c = expression[i];
			string.push_back();
			std::list<std::string>::iterator iterator = string.begin();
			cout << *iterator;
		}
		else
		{
			std::cerr << "Error: Invalid value." << endl;
			return false;
		}
		i++;
	}
	return true;
}

void RPN::calculate(const std::string &av)
{
	if (getList(av) == false)
		return ;
	std::list<std::string>::iterator iterator = string.begin();
	cout << *iterator;
}