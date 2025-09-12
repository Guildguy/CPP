#include "Fixed.hpp"

const int	Fixed::Bits = 8;

 //Construtor
Fixed::Fixed() : Number(0) {}

 //Destrutor
Fixed::~Fixed() {}

 //Cópia do construtor
Fixed::Fixed(const Fixed &copy)
{
	this->Number = copy.Number;
}

 //operador de sobrecarga
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

/*************** sobrecarga de construtor ************** */
 //sobrecarga de contrutor para inicialização de int
Fixed::Fixed(const int iNbr)
{
	Number = iNbr << Bits;
}

 //sobrecarga de contrutor para inicialização de float
Fixed::Fixed(const float fNbr)
{
	Number = roundf(fNbr * (1 << Bits));
}

/*************** sobrecarga de operador ************** */
 //sobrecarga de operador, atriuição de cópia
Fixed&	Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->Number = fixed.Number;
	return (*this);
}

/***************** métodos ***************** */
 //método que converte Number para um int
int	Fixed::toInt(void) const
{
	return (Number >> Bits);
}

 //método que converte Number para um float
float	Fixed::toFloat(void) const
{
	return ((float)Number / (1 << Bits));
}

/***************** operador aritmético ***************** */

Fixed	Fixed::operator+(const Fixed &N) const
{
	return (Fixed(this->toFloat() + N.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &N) const
{
	return (Fixed(this->toFloat() - N.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &N) const
{
	return (Fixed(this->toFloat() * N.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &N) const
{
	return (Fixed(this->toFloat() / N.toFloat()));
}

/***************** operador de comparação ***************** */

bool	Fixed::operator<(const Fixed &N) const
{
	return (Number < N.Number);
}

bool	Fixed::operator>(const Fixed &N) const
{
	return (Number > N.Number);
}

bool	Fixed::operator<=(const Fixed &N) const
{
	return (Number <= N.Number);
}

bool	Fixed::operator>=(const Fixed &N) const
{
	return (Number >= N.Number);
}

bool	Fixed::operator==(const Fixed &N) const
{
	return (Number == N.Number);
}

bool	Fixed::operator!=(const Fixed &N) const
{
	return (Number != N.Number);
}

/***************** operador incr./decr. ******************* */

Fixed&	Fixed::operator++(void)
{
	Number += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temporary = *this;
	Number += 1;
	return (temporary);
}

/*Fixed&	Fixed::operator--(void)
{
	Number -= 1;
	return (*this);
}*/

/*Fixed	Fixed::operator--(int)
{
	Fixed	temporary = *this;
	Number -= 1;
	return (temporary);
}*/

Fixed&		Fixed::min(Fixed &n1, Fixed &n2)
{
	return ((n1.toFloat() < n2.toFloat()) ? n1 : n2);
}

const Fixed	Fixed::min(const Fixed &n1, const Fixed &n2)
{
	return ((n1.toFloat() < n2.toFloat()) ? n1 : n2);
}

Fixed&		Fixed::max(Fixed &n1, Fixed &n2)
{
	return ((n1.toFloat() > n2.toFloat()) ? n1 : n2);
}

const Fixed	Fixed::max(const Fixed &n1, const Fixed &n2)
{
	return ((n1.toFloat() > n2.toFloat()) ? n1 : n2);
}
