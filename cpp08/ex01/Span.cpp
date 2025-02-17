#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw Span::SpanFullException();
	_numbers.push_back(n);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; i++)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();
	return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > static_cast<int>(_maxSize - _numbers.size()))
		throw Span::SpanFullException();
	_numbers.insert(_numbers.end(), begin, end);
}

void Span::print() const
{
	std::cout << "Span: ";
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i] << " ";
	std::cout << std::endl;
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span is full!";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate span!";
}