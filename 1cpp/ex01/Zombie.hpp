#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class	Zombie
{
	private:
		std::string	Name;


	public:
		Zombie();
		~Zombie();

		void				announce(void);
		static Zombie*		zombieHorde(int N, std::string name);
		static int			getHordeSize(void);
		static std::string	getZombieName(void);

		void				SetName(const std::string& newName);
};

#endif
