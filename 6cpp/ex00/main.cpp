#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	std::string	input;

	if ( ac == 2)
	{
		input = av[1];
		ScalarConverter::convert(input);
	}
	else
		std::cout << "Usage: ./ScalarConverter <literal>\n";
	
	return (0);
}
