#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other): stack(other.stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		stack = other.stack;
	return *this;
}

RPN::~RPN() {}

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isdigit(token[0]))
		{
			stack.push_back(token[0] - '0');
		}
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: Bad using. Example: ./RPN \"3 6 + 8 -\"" << std::endl;
				return;
			}
			int b = stack.back(); stack.pop_back();
			int a = stack.back(); stack.pop_back();
			int result;

			switch (token[0])
			{
				case '+': result = a + b; break;
				case '-': result = a - b; break;
				case '*': result = a * b; break;
				case '/':
					if (b == 0)
					{
						std::cerr << "Error: You can't using 0." << std::endl;
						return;
					}
					result = a / b;
					break;
				default:
					std::cerr << "Error: Bad using. Example: ./RPN \"3 6 + 8 -\"" << std::endl;
					return;
			}
			stack.push_back(result);
		}
		else
		{
			std::cerr << "Error: invalid value: " << token << std::endl;
			return;
		}
	}

	if (stack.size() != 1)
	{
		std::cerr << "Error: invalid expression." << std::endl;
		return;
	}

	std::cout << stack.back() << std::endl;
}
