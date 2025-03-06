#include "Span.hpp"

Span::Span(unsigned int n) : _n(n), _numbers() {}

Span::~Span() {}

Span::Span(const Span &other) : _n(other._n), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _n)
		throw Span::SpanOverflowException();
	_numbers.push_back(number);
}

void Span::addNumbers(unsigned int size)
{
	if (_numbers.size() + size > _n)
		throw Span::SpanOverflowException();
	for (unsigned int i = 0; i < size; i++)
		_numbers.push_back(i);
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw Span::SpanOverflowException();
	
	std::vector<int> vec = _numbers;
	std::sort(vec.begin(), vec.end());

	return vec[vec.size() - 1] - vec[0];
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw Span::SpanOverflowException();
	
	std::vector<int> sorted = _numbers;

	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < min)
			min = sorted[i] - sorted[i - 1];
	}
	return min;
}