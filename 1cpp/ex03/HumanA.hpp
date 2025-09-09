#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon&		type;
		std::string	name;
	
	public:
		HumanA(std::string name, Weapon& type);
		~HumanA();

		void	attack(void);
};

#endif
