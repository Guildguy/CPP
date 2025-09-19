#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->HP = 100;
	this->EP = 100;
	this->AttackDmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametric constructor called for FragTrap " << this->getName() << std::endl;
	this->HP = 100;
	this->EP = 100;
	this->AttackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
}

FragTrap&	FragTrap::operator=(const FragTrap &FragTrap)
{
	if (this != &FragTrap)
		ClapTrap::operator=(FragTrap);
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const FragTrap& FragTrap)
{
	std::cout << "---------------------- STATUS ----------------------" << std::endl;
	os << "| Name: " << FragTrap.getName() << " | Attack Damage: " << FragTrap.getAttack() << \
	" | HP: " << FragTrap.getHP() << " | EP: " << FragTrap.getEP() << " |" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	return (os);
}

void	FragTrap::highFivesGuys()
{
	if (this->HP <= 0)
		std::cout << this->getName() << " is dead and can't do a HighFive" << std::endl;
	else
		std::cout << this->getName() << " said 'Lets do a HighFive bro'" << std::endl;
}
