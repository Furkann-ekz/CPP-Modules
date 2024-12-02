#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					rawbits;
		static const int	fractionalbits = 8;
	public:
		Fixed();
		Fixed(int value);
		Fixed(const float value);
		Fixed(const Fixed &cpy_fixed);
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed &operator = (const Fixed &cpy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &min(Fixed &r1, Fixed &r2);
		static Fixed &max(Fixed &r1, Fixed &r2);
		const static Fixed &min(const Fixed &r1, const Fixed &r2);
		const static Fixed &max(const Fixed &r1, const Fixed &r2);
		bool operator < (const Fixed &r) const;
		bool operator > (const Fixed &r) const;
		bool operator >= (const Fixed &r) const;
		bool operator <= (const Fixed &r) const;
		bool operator == (const Fixed &r) const;
		bool operator != (const Fixed &r) const;
		float operator + (const Fixed &r) const;
		float operator - (const Fixed &r) const;
		float operator / (const Fixed &r) const;
		float operator * (const Fixed &r) const;
		~Fixed();
};

std::ostream &operator << (std::ostream &output, const Fixed &fixed);

#endif