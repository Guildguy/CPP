#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					fixedPointNUmber;
		static const int	fractionalBits;
	
	public:
		Fixed(); //contrutor
		Fixed(const Fixed &copy); //construtor de cópia
		Fixed&	operator=(const Fixed &fixed); 	//operador de atribuição
		~Fixed(); //destrutor

		int		getRawBits(void) const;

		void	setRawBits(int const raw);
};

#endif
