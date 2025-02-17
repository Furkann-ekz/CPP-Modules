#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void print() const;

		class SpanFullException : public std::exception
		{
			const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			const char* what() const throw();
		};
};

#endif