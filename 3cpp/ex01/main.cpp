#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Enemy("Sephiroth");
	ScavTrap	Person;

	Enemy.Attack(Person.getName());
	Person.takeDamage(Enemy.getAttack());
	Person.Attack(Enemy.getName());
	Enemy.takeDamage(Person.getAttack());
	Person.beRepaired(100);
	Person.guardGate();
	return (0);
}
