#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon() {}

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(const std::string& newType)
{
	this->type = newType;
}
