#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					fixedPointNUmber;
		static const int	fractionalBits;
	
	public:
		Fixed(const int	value); //contrutor
		Fixed(const Fixed &copy); //construtor de cópia
		Fixed&	operator=(const Fixed &fixed); 	//operador de atribuição
		~Fixed(); //destrutor

		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif
