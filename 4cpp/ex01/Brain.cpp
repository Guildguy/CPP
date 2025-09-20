#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain&	Brain::operator=(const Brain& Brain)
{
	if (this != &Brain)
	{
		for(int i = 0; i < 100; i++)
			this->ideias[i] = Brain.ideias[i];
	}
	return (*this);
}
