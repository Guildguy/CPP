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
		Fixed(const int iNbr);
		Fixed(const float fNbr);
		Fixed(const Fixed &copy); //construtor de cópia
		Fixed&	operator=(const Fixed &fixed); 	//operador de atribuição
		~Fixed(); //destrutor

		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
