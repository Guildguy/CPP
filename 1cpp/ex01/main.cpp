#include "Zombie.hpp"

int	main(void)
{
	int			HordeSize;
	std::string	Name;
	Zombie*		Horde;
	
	HordeSize = Zombie::getHordeSize();
	if (HordeSize == -1)
		return (1);
	Name = Zombie::getZombieName();
	Horde = Zombie::zombieHorde(HordeSize, Name); 
	std::cout << "Your " << HordeSize << " rotten ones named [" << Name << "] were created!" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < HordeSize; i++)
	    Horde[i].announce();
	std::cout << std::endl;
	delete[] Horde;
	return (0);
}
