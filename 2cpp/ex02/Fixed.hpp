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
		Fixed(); //construtor
		~Fixed(); //destrutor

		Fixed(const Fixed &copy); //construtor de cópia
		Fixed(const int iNbr); //sobrecarga de contrutor para inicialização de int
		Fixed(const float fNbr); //sobrecarga de contrutor para inicialização de float

		//operador de atribuição
		Fixed&				operator=(const Fixed &fixed);

		//operador aritmético
		Fixed				operator+(const Fixed &N) const;
		Fixed				operator-(const Fixed &N) const;
		Fixed				operator*(const Fixed &N) const;
		Fixed				operator/(const Fixed &N) const;

		//operador de comparação
		bool				operator<(const Fixed &N) const;
		bool				operator>(const Fixed &N) const;
		bool				operator<=(const Fixed &N) const;
		bool				operator>=(const Fixed &N) const;
		bool				operator==(const Fixed &N) const;
		bool				operator!=(const Fixed &N) const;

		//operador de incremento/decremento
		Fixed				&operator++();   //++i;
		Fixed				operator++(int); //i++;
		//Fixed				&operator--();   //--i;
		//Fixed				operator--(int); //i--;

		int					toInt(void) const;
		float				toFloat(void) const;

		static Fixed		&min(Fixed &n1, Fixed &n2);
		static const Fixed	min(const Fixed &n1, const Fixed &n2);
		static Fixed		&max(Fixed &n1, Fixed &n2);
		static const Fixed	max(const Fixed &n1, const Fixed &n2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
