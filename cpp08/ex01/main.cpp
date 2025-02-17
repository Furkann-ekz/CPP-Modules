#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		Span sp(10000);
		std::vector<int> range;
		for (int i = 0; i < 10000; ++i)
			range.push_back(i);
		sp.addRange(range.begin(), range.end());

		std::cout << "Large Span Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Large Span Longest: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}