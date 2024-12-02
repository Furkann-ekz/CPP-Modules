#include "Fixed.hpp"

Fixed::Fixed()
{
	rawbits = 0;
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& cpy)
{
	cout << "Copy constructor called" << endl;
	rawbits = cpy.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed& opr)
{
	if (this != &opr)
	{
		rawbits = opr.rawbits;
		cout << "Copy assigment operator called" << endl;
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (rawbits);
}

void Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	rawbits = raw;
}

Fixed::~Fixed()
{
	cout << "Destructor called"<< endl;
}
