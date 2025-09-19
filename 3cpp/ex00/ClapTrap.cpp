#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Cloud")/*, HP(10), EP(10), AttackDmg(0)*/
{
	std::cout << "Default constructor called" << std::endl;
	this->PersonStatus();
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << name << std::endl;
};

ClapTrap::ClapTrap(std::string name) : name(name)/*, HP(10), EP(10), AttackDmg(0)*/
{
	std::cout << "Parametric constructor called for ClapTrap " << name << std::endl;
	this->PersonStatus();
}

void	ClapTrap::PersonStatus(void)
{
	this->HP = 10;
	this->EP = 10;
	this->AttackDmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ClapTrap)
{
	if (this != &ClapTrap)
	{
		this->name = ClapTrap.name;
		this->HP = ClapTrap.HP;
		this->EP = ClapTrap.EP;
		this->AttackDmg = ClapTrap.AttackDmg;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ClapTrap& ClapTrap)
{
	std::cout << "---------------------- STATUS ----------------------" << std::endl;
	os << "| Name: " << ClapTrap.getName() << " | Attack Damage: " << ClapTrap.getAttack() << \
	" | HP: " << ClapTrap.getHP() << " | EP: " << ClapTrap.getEP() << " |" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	return (os);
}

void	ClapTrap::Attack(const std::string& target)
{
	if (HP == 0)
	{
		std::cout << "ClapTrap " << name << " is out of HP and cannot attack." << std::endl;
		return ;
	}
	if (EP == 0)
	{
		std::cout << "ClapTrap " << name << " is out of EP and cannot attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDmg << \
	" points of damage!" << std::endl;
	EP--;
	std::cout << "ClapTrap " << name << " now has " << EP << "/10 EP left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << \
	" points of damage!" << std::endl;
	if (amount >= HP)
	{
		HP = 0;
		std::cout << "ClapTrap " << name << " has been defeated!" << std::endl;
	}
	else
	{
		HP -= amount;
		std::cout << "ClapTrap " << name << " now has " << HP << \
		"/10 HP left." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (HP == 0)
	{
		std::cout << "ClapTrap " << name << \
		" is out of HP and cannot be repaired." << std::endl;
		return ;
	}
	if (EP == 0)
	{
		std::cout << "ClapTrap " << name << \
		" is out of EP and cannot repair itself." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << \
	" repairs itself, regaining " << amount << " points of health!" << std::endl;
	if (HP + amount > 10)
		std::cout << "ClapTrap " << name << \
		" now has 10/10 HP!" << std::endl;
	else
		std::cout << "ClapTrap " << name << \
		" now has "  << HP + amount << "/10!" << std::endl;
	EP--;
	std::cout << "ClapTrap " << name << " now has " << EP << \
	"/10 EP left." << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (this->name);
}

unsigned int	ClapTrap::getAttack() const
{
	return (this->AttackDmg);
}

unsigned int	ClapTrap::getHP() const
{
	return (this->HP);
}

unsigned int	ClapTrap::getEP() const
{
	return (this->EP);
}
