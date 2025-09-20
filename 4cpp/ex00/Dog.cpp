#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << this->getType() << " constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->getType() << " destructor called" << std::endl;
}

Dog::Dog(const Dog& copy)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = copy;
}

Dog	Dog::operator=(const Dog& Dog)
{
	if (this != &Dog)
		Animal::operator=(Dog);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->getType() << ": Auf Auf!" << std::endl;
}
