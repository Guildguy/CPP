#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

 //Construtor
Fixed::Fixed() : fixedPointNumber(0) {}

 //Destrutor
Fixed::~Fixed() {}

 //Cópia do construtor
Fixed::Fixed(const Fixed &copy)
{
	this->fixedPointNumber = copy.fixedPointNumber;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
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
	fixedPointNumber = iNbr << fractionalBits;
}

 //sobrecarga de contrutor para inicialização de float
Fixed::Fixed(const float fNbr)
{
	fixedPointNumber = roundf(fNbr * (1 << fractionalBits));
}

/*************** sobrecarga de operador ************** */
 //sobrecarga de operador, atriuição de cópia
Fixed&	Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->fixedPointNumber = fixed.fixedPointNumber;
	return (*this);
}

/***************** métodos ***************** */
 //método que converte fixedPointNumber para um int
int	Fixed::toInt(void) const
{
	return (fixedPointNumber >> fractionalBits);
}

 //método que converte fixedPointNumber para um float
float	Fixed::toFloat(void) const
{
	return ((float)fixedPointNumber / (1 << fractionalBits));
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
	return (fixedPointNumber < N.fixedPointNumber);
}

bool	Fixed::operator>(const Fixed &N) const
{
	return (fixedPointNumber > N.fixedPointNumber);
}

bool	Fixed::operator<=(const Fixed &N) const
{
	return (fixedPointNumber <= N.fixedPointNumber);
}

bool	Fixed::operator>=(const Fixed &N) const
{
	return (fixedPointNumber >= N.fixedPointNumber);
}

bool	Fixed::operator==(const Fixed &N) const
{
	return (fixedPointNumber == N.fixedPointNumber);
}

bool	Fixed::operator!=(const Fixed &N) const
{
	return (fixedPointNumber != N.fixedPointNumber);
}

/***************** operador incr./decr. ******************* */

Fixed&	Fixed::operator++(void)
{
	fixedPointNumber += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temporary = *this;
	fixedPointNumber += 1;
	return (temporary);
}

/*Fixed&	Fixed::operator--(void)
{
	fixedPointNumber -= 1;
	return (*this);
}*/

/*Fixed	Fixed::operator--(int)
{
	Fixed	temporary = *this;
	fixedPointNumber -= 1;
	return (temporary);
}*/

Fixed&		Fixed::min(Fixed &n1, Fixed &n2)
{
	return ((n1 < n2) ? n1 : n2);
}

const Fixed	Fixed::min(const Fixed &n1, const Fixed &n2)
{
	return ((n1 < n2) ? n1 : n2);
}

Fixed&		Fixed::max(Fixed &n1, Fixed &n2)
{
	return ((n1 > n2) ? n1 : n2);
}

const Fixed	Fixed::max(const Fixed &n1, const Fixed &n2)
{
	return ((n1 > n2) ? n1 : n2);
}
