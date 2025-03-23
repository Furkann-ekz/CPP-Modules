#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other): arg(other.arg) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		arg = other.arg;
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
		if (isdigit(expression[i]) && expression[i] <= '9' && expression[i] > '0')
		{
			num++;
			arg.push_back(expression[i]);
		}
		else if (operatorControl(expression[i]))
		{
			op++;
			arg.push_back(expression[i]);
		}
		else
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
	arg.push_back('0');
	return true;
}

bool RPN::argControl(void)
{
	std::list<char>::iterator iterator = arg.begin();
	char x;
	x = *iterator;
	iterator++;
	while (*iterator != '0')
	{
		if (operatorControl(x) && operatorControl(*iterator))
		{
			std::cerr << "Error: Bad using. Example: ./RPN '3 6 + 8 -'" << endl;
			return false;
		}
		x = *iterator;
		iterator++;
	}
	return true;
}

long long process(int a, int b, char c)
{
	long long	x;
	bool		control = false;

	if (a > 0 && b > 0)
		control = true;
	if (c == '+')
		x = a + b;
	else if (c == '*')
		x = a * b;
	else if (c == '-')
		x = a - b;
	else if (c == '/')
		x = a / b;
	if (x <= 0 && control == true)
	{
		std::cerr << "Error: Result is not within integer limits." << endl;
		return (2147483648);
	}
	if (x > 2147483647 && x < -2147483648)
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
	if (argControl() == false)
		return ;
	std::list<char>::iterator iterator = arg.begin();
	long long a = *iterator - 48;
	iterator++;
	long long b = *iterator - 48;
	while (*iterator != '0')
	{
		iterator++;
		a = process(a, b, *iterator);
		if (a > 2147483647 || a < -2147483648)
			return ;
		if (*iterator == '+' || *iterator == '-' || *iterator == '*' || *iterator == '/')
			iterator++;
		b = *iterator - 48;
	}
	cout << a << endl;
}
