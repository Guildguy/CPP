#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type)
{
	this->type = type;
	this->name = name;
}