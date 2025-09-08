#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : type(type), name(name) {}

HumanA::~HumanA() {}

void	HumanA::attack(void)
{	
	std::cout << std::endl << name << " Attacked with his " << type.getType() << "!" << std::endl;
}
