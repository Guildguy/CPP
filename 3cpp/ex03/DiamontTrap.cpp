#include "DiamontTrap.hpp"

DiamontTrap::DiamontTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamontTrap default constructor called" << std::endl;
	this->HP = 100;
	this->EP = 50;
	this->AttackDmg = 30;
}

DiamontTrap::~DiamontTrap()
{
	std::cout << "DiamontTrap " << this->getName() << " destructor called" << std::endl;
}

DiamontTrap::DiamontTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "Parametric constructor called for DiamontTrap " << this->getName() << std::endl;
	this->HP = 100;
	this->EP = 50;
	this->AttackDmg = 30;
}

DiamontTrap::DiamontTrap(const DiamontTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
}

DiamontTrap&	DiamontTrap::operator=(const DiamontTrap& DiamontTrap)
{
	if (this != &DiamontTrap)
		ClapTrap::operator=(DiamontTrap);
	return (*this);
}

void	DiamontTrap::Attack(const std::string& target)
{
	ScavTrap::Attack(target);
}

void	DiamontTrap::whoAmI(void)
{
	std::cout << "I am ClapTrap: " << ClapTrap::name << std::endl;
	std::cout << "I am DiamontTrap: " << this->name << std::endl;
}
