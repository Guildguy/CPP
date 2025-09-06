#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	Name;
	
	public:
		Zombie(std::string Name);
		~Zombie();

		void	announce(void);
};

void	randomChump(std::string Name);
Zombie* newZombie( std::string Name);

#endif