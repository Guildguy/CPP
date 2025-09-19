#ifndef DIAMONTTRAP_HPP
# define DIAMONTTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamontTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	public:
		DiamontTrap();
		~DiamontTrap();

		DiamontTrap(std::string name);
		DiamontTrap(const DiamontTrap &copy);
		DiamontTrap&	operator=(const DiamontTrap& DiamontTrap);
		
		void	Attack(const std::string& target);
		void	whoAmI(void);
};

#endif