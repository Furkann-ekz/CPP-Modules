#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

using std::cout;
using std::endl;

class Fixed
{
	private:
		int					rawbits;
		static const int	fractionalbits = 8;
	public:
		Fixed();
		Fixed(const Fixed& cpy);
		~Fixed();
		Fixed	&operator=(const Fixed& opr);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif