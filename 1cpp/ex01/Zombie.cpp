#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << "Zombie [" << Name << "] was killed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName(const std::string& newName)
{
	this->Name = newName;
}

int	Zombie::getHordeSize(void)
{
	std::string	ZombieQnt;
	int			Size;

	std::cout << std::endl << "Give the size of the horde!" << std::endl;
	getline(std::cin, ZombieQnt);
	if (ZombieQnt.empty())
	{
		std::cout << "need to pass a number!" << std::endl;
		return (-1);
	}
	std::stringstream ss(ZombieQnt);
	if (!(ss >> Size) || !ss.eof())
	{
		std::cout << std::endl << "type at least one!" << std::endl;
		return (-1);
	}
	if (Size > 10000 || Size <= 0)
	{
		std::cout << std::endl << "Invalid: type a number between 1 to 10000" << std::endl;
		return (-1);
	}
	return (Size);
}

std::string Zombie::getZombieName(void)
{
	std::string	Name;

	while (true)
	{
		std::cout << "Which name?" << std::endl;
		getline(std::cin, Name);
		if (!Name.empty())
		{
			return (Name);
		}
		std::cout << std::endl << "need to pass a name!" << std::endl;
	}
}
