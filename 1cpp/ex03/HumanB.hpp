#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon*		type;
		std::string	name;
	
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack(void);

		void	setWeapon(Weapon* newType);
};

#endif
