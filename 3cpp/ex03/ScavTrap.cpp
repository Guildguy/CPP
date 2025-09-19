#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->HP = 100;
	this->EP = 50;
	this->AttackDmg = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametric constructor called for ScavTrap " << this->getName() << std::endl;
	this->HP = 100;
	this->EP = 50;
	this->AttackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	*this = copy;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ScavTrap)
{
	if (this != &ScavTrap)
		ClapTrap::operator=(ScavTrap);
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ScavTrap& ScavTrap)
{
	std::cout << "---------------------- STATUS ----------------------" << std::endl;
	os << "| Name: " << ScavTrap.getName() << " | Attack Damage: " << ScavTrap.getAttack() << \
	" | HP: " << ScavTrap.getHP() << " | EP: " << ScavTrap.getEP() << " |" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	return (os);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::Attack(const std::string& target)
{
	if (HP == 0)
	{
		std::cout << "ScavTarp " << name << " is out of HP and cannot attack." << std::endl;
		return ;
	}
	if (EP == 0)
	{
		std::cout << "ScavTarp " << name << " is out of EP and cannot attack." << std::endl;
		return ;
	}
	std::cout << "ScavTarp " << name << " attacks " << target << ", causing " << AttackDmg << \
	" points of damage!" << std::endl;
	EP--;
	std::cout << "ScavTarp " << name << " now has " << EP << "/50 EP left." << std::endl;
}
