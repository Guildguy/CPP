#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Enemy("Sephiroth");
	ScavTrap	Person;

	std::cout << Enemy << std::endl;
	std::cout << Person << std::endl;
	Enemy.Attack(Person.getName());
	if (Enemy.getHP() > 0)
		Person.takeDamage(Enemy.getAttack());
	Person.Attack(Enemy.getName());
	if (Person.getHP() > 0)
		Enemy.takeDamage(Person.getAttack());
	Person.beRepaired(100);
	Person.guardGate();
	std::cout << Enemy << std::endl;
	std::cout << Person << std::endl;
	return (0);
}
