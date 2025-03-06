#include <iostream>
#include "Span.hpp"

void	pdf_test()
{
	Span sp(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Numbers added successfully." << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		sp.addNumber(42);
	}
	catch (const Span::SpanOverflowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

#include "Span.hpp"

int main()
{
	pdf_test();

	Span sp2(10);
	try
	{
		sp2.addNumbers(8);
		std::cout << "8 numbers added successfully." << std::endl;

		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (const Span::SpanOverflowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	Span sp3(3);
	try
	{
		sp3.addNumber(1);
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	}
	catch (const Span::SpanOverflowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}