#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int intValue)
{
	cout << "Int constructor called" << endl;
	value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	cout << "Float constructor called" << endl;
	value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	cout << "Copy constructor called" << endl;
	*this = other;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &other) {
		value = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits() const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat() const
{
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
