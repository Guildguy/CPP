#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					fixedPointNumber;
		static const int	fractionalBits;
	
	public:
		Fixed();
		~Fixed(); //destrutor

		Fixed(const Fixed &copy); //construtor de cópia
		
		Fixed(const int iNbr); //sobrecarga de contrutor para iniciallização de int
		Fixed(const float fNbr); //sobrecarga de contrutor para iniciallização de float

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed&	operator=(const Fixed &fixed); 	//operador de atribuição

		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
