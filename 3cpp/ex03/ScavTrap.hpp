#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();

		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap&	operator=(const ScavTrap& ScavTrap);	

		void	Attack(const std::string& target);
		void	guardGate();
};

#endif