#include "Zombie.hpp"

Zombie::Zombie(std::string Name)
{
	this->Name = Name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie [" << Name << "] was killed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << std::endl << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
