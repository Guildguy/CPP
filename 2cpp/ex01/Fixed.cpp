#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed(const int value) : fixedPointNUmber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNUmber = copy.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixedPointNUmber = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNUmber);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointNUmber = raw;
}
