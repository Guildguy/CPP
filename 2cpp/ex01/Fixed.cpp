#include "Fixed.hpp"

const int	Fixed::Bits = 8;

Fixed::Fixed() : Number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int iNbr)
{
	std::cout << "Int constructor called" << std::endl;
	Number = iNbr << Bits;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::Fixed(const float fNbr)
{
	std::cout << "Float contructor called" << std::endl;
	Number = roundf(fNbr * (1 << Bits));
}

int	Fixed::toInt(void) const
{
	return (Number >> Bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)Number / (1 << Bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->Number = copy.Number;
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->Number = fixed.Number;
	return (*this);
}
