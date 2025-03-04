#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // 14

	Span sp2 = Span(1);
	sp2.addNumber(42);
	try 
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		sp.addNumber(100);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	Span big_sp = Span(10000);
	std::srand(std::time(0));
	for (int i = 0; i < 10000; ++i)
		big_sp.addNumber(std::rand() % 1000000);
	std::cout << "Big Span - Shortest span: " << big_sp.shortestSpan() << std::endl;
	std::cout << "Big Span - Longest span: " << big_sp.longestSpan() << std::endl;

	return 0;
}