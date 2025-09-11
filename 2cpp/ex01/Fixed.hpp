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
		Fixed(const int iNbr);
		Fixed(const float fNbr);

		Fixed&	operator=(const Fixed &fixed); 	//operador de atribuição

		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
