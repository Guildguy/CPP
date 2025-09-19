#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	HP;
		unsigned int	EP;
		unsigned int	AttackDmg;
		//void			PersonStatus();

	public:
		ClapTrap();
		~ClapTrap();

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap&	operator=(const ClapTrap& ClapTrap);	

		void	Attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName() const;
		unsigned int	getAttack() const;
		unsigned int	getHP() const;
		unsigned int	getEP() const;
};

std::ostream&	operator<<(std::ostream& os, const ClapTrap& ClapTrap);

#endif