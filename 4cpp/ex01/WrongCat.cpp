#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << this->getType() << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->getType() << " destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = copy;
}

WrongCat	WrongCat::operator=(const WrongCat& WrongCat)
{
	if (this != &WrongCat)
		WrongAnimal::operator=(WrongCat);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << this->getType() << ": Meown!" << std::endl;
}

