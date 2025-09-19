#include "DiamontTrap.hpp"

int	main(void)
{
	FragTrap	Enemy("Sephiroth");
	DiamontTrap	Person("Cloud");

	std::cout << Enemy << std::endl;
	std::cout << Person << std::endl;
	Person.whoAmI();
	Enemy.Attack(Person.getName());
	if (Enemy.getHP() > 0)
		Person.takeDamage(Enemy.getAttack());
	Person.Attack(Enemy.getName());
	if (Person.getHP() > 0)
		Enemy.takeDamage(Person.getAttack());
	Person.beRepaired(100);
	Person.guardGate();
	if (Enemy.getHP() <= 0)
	{
		std::cout << "you can't do a HighFive with " << Enemy.getName() << \
		" 'cause it's dead!" << std::endl;
		std::cout << Enemy << std::endl;
		std::cout << Person << std::endl;
		return (1);
	}
	Enemy.highFivesGuys();
	std::cout << Enemy << std::endl;
	std::cout << Person << std::endl;
	return (0);
}
