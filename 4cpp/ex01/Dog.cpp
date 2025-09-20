#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << this->getType() << " constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << this->getType() << " destructor called" << std::endl;
}

Dog::Dog(const Dog& copy)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog	Dog::operator=(const Dog& Dog)
{
	if (this != &Dog)
	{
		Animal::operator=(Dog);
		delete this->brain;
		this->brain = new Brain(*Dog.brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->getType() << ": Auf Auf!" << std::endl;
}
