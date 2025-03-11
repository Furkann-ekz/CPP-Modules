#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : numbers(other.numbers) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other) {
		numbers = other.numbers;
	}
	return *this;
}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::performOperation(int a, int b, const std::string& op) const
{
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/")
	{
		if (b == 0)
		{
			std::cerr << "Error: Division by zero" << std::endl;
			return 0;
		}
		return a / b;
	}
	return 0;
}

void RPN::calculate(const std::string& expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
		{
			int num = token[0] - '0';
			numbers.push(num);
		}
		else if (isOperator(token))
		{
			if (numbers.size() < 2)
			{
				std::cerr << "Error: Invalid expression (not enough operands)" << std::endl;
				return;
			}
			int b = numbers.top(); numbers.pop();
			int a = numbers.top(); numbers.pop();
			int result = performOperation(a, b, token);
			numbers.push(result);
		}
		else {
			std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
			return;
		}
	}

	if (numbers.size() != 1)
	{
		std::cerr << "Error: Invalid expression (too many operands)" << std::endl;
		return;
	}

	std::cout << numbers.top() << std::endl;
}