#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	person;

	std::cout << person;
	person.Attack("Alice");
	std::cout << "Alice attacked, ";
	person.takeDamage(8);
	person.beRepaired(2);
	std::cout << person;
	return (0);
}
