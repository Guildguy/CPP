#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];

	if (N <= 0)
		return (NULL);
	for (int i = 0; i < N; i++)
	{
		std::stringstream	ss;
		ss << name << " " << i;
		std::string newName = ss.str();
		
		horde[i].SetName(newName);
	}
	return (horde);
}
