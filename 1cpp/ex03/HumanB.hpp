#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon		type;
		std::string	name;
	
	public:
		HumanB();
		~HumanB();

		void	attack(std::string name);

		void	setWeapon(Weapon& type);
};

#endif