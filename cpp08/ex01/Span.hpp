#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _numbers;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		void addNumbers(unsigned int size);
		int shortestSpan();
		int longestSpan();
		class SpanOverflowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Span's capacity is full, no more elements can be added or size less than 2.";
				}
		};


};

#endif