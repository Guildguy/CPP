#include "Harl.hpp"

int	main(int c, char **v)
{
	Harl	Harl;
	std::string	level;

	if (c != 2)
	{
		std::cerr << "How to use: ./harl [filter]" << std::endl;
		std::cerr << "Filters: DEBUG, INFO, WARNING and ERROR" << std::endl;
		return (1);
	}
	level = v[1];
	Harl.complain(level);
	return (0);
}
