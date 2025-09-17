#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : HP(10), EP(10), ATK(0) {};

ClapTrap::~ClapTrap() {};

ClapTrap::ClapTrap(const ClapTrap& ClapTrap)
{
	this->HP = ClapTrap.HP;
	this->EP = ClapTrap.EP;
	this->ATK = ClapTrap.ATK;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ClapTrap)
{
	if (this != &ClapTrap)
	{
		this->HP = ClapTrap.HP;
		this->EP = ClapTrap.EP;
		this->ATK = ClapTrap.ATK;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ClapTrap& ClapTrap)
{
	os << ClapTrap;
	return (os);
}

void	Attack(const std::string& target)
{}

void	takeDamage(unsigned int amount)
{}

void	beRepaired(unsigned int amount)
{}
