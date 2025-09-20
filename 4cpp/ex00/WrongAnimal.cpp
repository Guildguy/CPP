#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong")
{
	std::cout << "Default wrong constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default wrong destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "Default wrong copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
	if (this != &WrongAnimal)
		this->type = WrongAnimal.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->getType() << ": Random sound" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const WrongAnimal& WrongAnimal)
{
	os << WrongAnimal.getType();
	return (os);
}
