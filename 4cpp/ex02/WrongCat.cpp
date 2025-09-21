#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	this->brain = new Brain();
	std::cout << this->getType() << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	delete this->brain;
	std::cout << this->getType() << " destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
}

WrongCat	WrongCat::operator=(const WrongCat& WrongCat)
{
	if (this != &WrongCat)
	{
		WrongAnimal::operator=(WrongCat);
		delete this->brain;
		this->brain = new Brain(*WrongCat.brain);
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << this->getType() << ": Wrong Meown!" << std::endl;
}
