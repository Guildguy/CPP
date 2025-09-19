#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;

	a.Attack("Alice");
	std::cout << "Alice attacked, ";
	a.takeDamage(8);
	a.beRepaired(2);
	return (0);
}
