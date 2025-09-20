#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << this->getType() << " constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << this->getType() << " destructor called" << std::endl;
}

Cat::Cat(const Cat& copy)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat	Cat::operator=(const Cat& Cat)
{
	if (this != &Cat)
	{
		Animal::operator=(Cat);
		delete this->brain;
		this->brain = new Brain(*Cat.brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->getType() << ": Meown!" << std::endl;
}
