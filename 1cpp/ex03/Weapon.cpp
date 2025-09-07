#include "Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(const std::string& newType)
{
	this->type = newType;
}