#include "Zombie.hpp"

int	main(void)
{
	std::string	Name;
	Zombie* rottenZombie;

	std::cout << "enter a name to this rotten soul on the heap: ";
	getline(std::cin, Name);
	if (Name.empty())
	{
		std::cout << std::endl << "Choose a name to the dead one on the heap!" << std::endl;
		return (1);
	}
	rottenZombie = newZombie(Name);
	rottenZombie->announce();
	delete(rottenZombie);

	std::cout << std::endl << "enter a name to this rotten soul on the stack: ";
	getline(std::cin, Name);
	if (Name.empty())
	{
		std::cout << std::endl << "Choose a name to the dead one on the stack!" << std::endl;
		return (1);
	}
	randomChump(Name);
	std::cout << std::endl;

	return (0);
}
