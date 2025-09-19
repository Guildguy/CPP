#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	Enemy("Sephiroth");
	FragTrap	Person("Cloud");

	std::cout << Enemy << std::endl;
	std::cout << Person << std::endl;
	Enemy.Attack(Person.getName());
	if (Enemy.getHP() > 0)
		Person.takeDamage(Enemy.getAttack());
	Person.Attack(Enemy.getName());
	if (Person.getHP() > 0)
		Enemy.takeDamage(Person.getAttack());
	Person.beRepaired(100);
	if (Enemy.getHP() <= 0)
	{
		std::cout << "you can't do a HighFive with " << Enemy.getName() << \
		" 'cause it's dead!" << std::endl;
		return (1);
	}
	Person.highFivesGuys();
	std::cout << Enemy << std::endl;
	std::cout << Person << std::endl;
	return (0);
}
