#include "HumanB.hpp"

HumanB::HumanB(std::string name) : type(NULL), name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack(void)
{
	if (!type)
	{
		std::cout << std::endl << name << 	" doesn't have a weapon to attack!" << std::endl;
		return ;
	}
	std::cout << std::endl << name << " Attacked with his " << type->getType() << "!" << std::endl;
}

void	HumanB::setWeapon(Weapon* newType)
{
	this->type = newType;
}
