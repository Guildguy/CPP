#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
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

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::Fixed(const int iNbr)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointNumber = iNbr << fractionalBits;
}

Fixed::Fixed(const float fNbr)
{
	std::cout << "Float contructor called" << std::endl;
	fixedPointNumber = roundf(fNbr * (1 << fractionalBits));
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixedPointNumber = fixed.fixedPointNumber;
	return (*this);
}

int	Fixed::toInt(void) const
{
	return (fixedPointNumber >> fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)fixedPointNumber / (1 << fractionalBits));
}
