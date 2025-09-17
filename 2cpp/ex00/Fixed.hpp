#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					fixedPointNumber;
		static const int	fractionalBits;
	
	public:
		Fixed(); //contrutor
		~Fixed(); //destrutor

		Fixed(const Fixed &copy); //construtor de cópia

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed&	operator=(const Fixed &fixed); 	//operador de atribuição
};

#endif
