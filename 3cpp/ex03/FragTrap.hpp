#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();

		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap&	operator=(const FragTrap& FragTrap);	

		void	highFivesGuys(void);
};
#endif