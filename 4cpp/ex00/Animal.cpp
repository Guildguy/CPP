#include "Animal.hpp"

Animal::Animal() : type("none")
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default destructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Default copy constructor called" << std::endl;
	*this = copy;
}

Animal&	Animal::operator=(const Animal& Animal)
{
	if (this != &Animal)
		this->type = Animal.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << this->getType() << ": Random sound" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Animal& Animal)
{
	os << Animal.getType();
	return (os);
}
