#include "Span.hpp"

Span::Span(unsigned int N) : _N(N), _numbers() {}

Span::~Span() {}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	
	int min_val = *std::min_element(_numbers.begin(), _numbers.end());
	int max_val = *std::max_element(_numbers.begin(), _numbers.end());
	
	return max_val - min_val;
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	
	std::vector<int> sorted = _numbers;

	std::sort(sorted.begin(), sorted.end());
	
	int min_span = std::numeric_limits<int>::max();

	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < min_span)
			min_span = span;
	}
	return min_span;
}