#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other): arg(other.arg), ops(other.ops) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		arg = other.arg;
		ops = other.ops;
	}
	return *this;
}

RPN::~RPN() {}

bool operatorControl(const char c)
{
	std::string operators = "-+*/";
	size_t i = -1;
	while (++i < operators.length())
		if (operators[i] == c)
			return (true);
	return (false);
}

bool RPN::getList(const std::string &expression)
{
	size_t i = 0;
	int num = 0;
	int op = 0;
	
	while (i < expression.length())
	{
		while (isspace(expression[i]))
			i++;
		if (isdigit(expression[i]) && expression[i] <= '9' && expression[i] >= '0')
		{
			num++;
			arg.push_back(expression[i]);
		}
		if (operatorControl(expression[i]))
		{
			op++;
			ops.push_back(expression[i]);
		}
		if (!((isdigit(expression[i]) && expression[i] <= '9' && expression[i] >= '0') || (operatorControl(expression[i]))))
		{
			std::cerr << "Error: Invalid value." << endl;
			return false;
		}
		i++;
	}
	if (num != op + 1)
	{
		std::cerr << "Error: Bad using. Example: ./RPN '3 6 + 8 -'" << endl;
		return false;
	}
	arg.push_back('p');
	ops.push_back('p');
	i = 0;
	
	while (isspace(expression[i]))
		i++;
	if (expression[i] <= '9' && expression[i] >= '0')
		i++;
	while (isspace(expression[i]))
		i++;
	if (operatorControl(expression[i]))
	{
		std::cerr << "Error: Bad using. Example: ./RPN '3 6 + 8 -'" << endl;
		return false;
	}
	return true;
}

long process(int a, int b, char c)
{
	long	x = 0;

	if (c == '+')
		x = a + b;
	else if (c == '*')
		x = a * b;
	else if (c == '-')
		x = a - b;
	else if (c == '/')
		x = a / b;
	if (x > 2147483647 || x < -2147483648)
	{
		std::cerr << "Error: Result is not within integer limits." << endl;
		return (2147483648);
	}
	return (x);
}

void RPN::calculate(const std::string &av)
{
	if (getList(av) == false)
		return ;
	std::list<char>::iterator iterator = arg.begin();
	std::list<char>::iterator op = ops.begin();
	long a = *iterator - 48;
	iterator++;
	long b = *iterator - 48;
	while (*iterator != 'p')
	{
		a = process(a, b, *op);
		if (a > 2147483647 || a < -2147483648)
			return ;
		iterator++;
		if (*iterator != 'p')
			b = *iterator - 48;
		op++;
	}
	cout << a << endl;
}