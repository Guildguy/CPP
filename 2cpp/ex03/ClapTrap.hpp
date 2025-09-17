#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		unsigned int	HP;
		unsigned int	EP;
		std::string		ATK;

	public:
		ClapTrap();
		~ClapTrap();

		ClapTrap(const ClapTrap &copy);
		ClapTrap&	operator=(const ClapTrap& ClapTrap);	

		void	Attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

std::ostream&	operator<<(std::ostream& os, const ClapTrap& ClapTrap);

#endif