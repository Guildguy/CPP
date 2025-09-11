#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					Number;
		static const int	Bits;
	
	public:
		Fixed();
		~Fixed(); //destrutor

		Fixed(const Fixed &copy); //construtor de cópia

		Fixed&	operator=(const Fixed &fixed); 	//operador de atribuição
		Fixed	operator+(const Fixed &N) const;
		Fixed	operator-(const Fixed &N) const;
		Fixed	operator*(const Fixed &N) const;
		Fixed	operator/(const Fixed &N) const;

		bool	operator<(const Fixed &N) const;
		bool	operator>(const Fixed &N) const;
		bool	operator<=(const Fixed &N) const;
		bool	operator>=(const Fixed &N) const;
		bool	operator==(const Fixed &N) const;
		bool	operator!=(const Fixed &N) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
