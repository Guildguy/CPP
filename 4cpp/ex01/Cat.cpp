#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << this->getType() << " constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->getType() << " destructor called" << std::endl;
}

Cat::Cat(const Cat& copy)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = copy;
}

Cat	Cat::operator=(const Cat& Cat)
{
	if (this != &Cat)
		Animal::operator=(Cat);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->getType() << ": Meown!" << std::endl;
}

