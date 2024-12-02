#include "Fixed.hpp"

Fixed::Fixed()
{
	this->rawbits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy_fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy_fixed;
}
Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawbits = value << fractionalbits;
}

float Fixed::toFloat(void) const
{
	return ((float)this->rawbits / (1 << fractionalbits));
}

int Fixed::toInt(void) const
{

	return (this->rawbits >> this->fractionalbits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawbits = (int)roundf(value * pow(2,this->fractionalbits));
}

Fixed& Fixed::operator=(const Fixed &cpy)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &cpy)
		this->rawbits = cpy.rawbits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawbits);
}

void Fixed::setRawBits(int const raw)
{
	this->rawbits = raw;
}

std::ostream &operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return output;
}

Fixed &Fixed::operator++()
{
	this->rawbits++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->rawbits++;
	return (tmp);
}
Fixed &Fixed::operator--()
{
	this->rawbits--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->rawbits--;
	return (tmp);
}
Fixed & Fixed::min(Fixed &r1, Fixed &r2)
{
	return ((r1.rawbits > r2.rawbits) ? r2 : r1);
}
Fixed& Fixed::max(Fixed &r1, Fixed &r2)
{
	return ((r1.rawbits > r2.rawbits) ? r1 : r2);
}

const Fixed& Fixed::min(const Fixed &r1, const Fixed &r2)
{
	return ((r1.rawbits > r2.rawbits) ? r2 : r1);
}
const Fixed& Fixed::max(const Fixed &r1, const Fixed &r2)
{
	return ((r1.rawbits > r2.rawbits) ? r1 : r2);
}

bool Fixed::operator < (const Fixed &r) const
{
	return  (this->rawbits < r.rawbits);
}
bool Fixed::operator > (const Fixed &r) const
{
	return (this->rawbits > r.rawbits);
}
bool Fixed::operator >= (const Fixed &r) const
{
	return (this->rawbits >= r.rawbits);
}
bool Fixed::operator <= (const Fixed &r) const
{
	return (this->rawbits <= r.rawbits);
}
bool Fixed::operator == (const Fixed &r) const
{
	return (this->rawbits == r.rawbits);
}
bool Fixed::operator != (const Fixed &r) const
{
	return (this->rawbits != r.rawbits);
}
float Fixed::operator + (const Fixed &r) const
{
	return (this->toFloat() + r.toFloat());
}
float Fixed::operator - (const Fixed &r) const
{
	return (this->toFloat() - r.toFloat());
}
float Fixed::operator / (const Fixed &r) const
{
	return (this->toFloat() / r.toFloat());
}
float Fixed::operator * (const Fixed &r) const
{
	return (this->toFloat() * r.toFloat());
}
