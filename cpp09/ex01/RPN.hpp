#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN 
{
	private:
		std::stack<int> numbers;

		bool isOperator(const std::string& token) const;
		int performOperation(int a, int b, const std::string& op) const;

	public:
		RPN();
		RPN(const RPN& other);
		~RPN();
		RPN& operator=(const RPN& other);

		void calculate(const std::string& expression);
};

#endif