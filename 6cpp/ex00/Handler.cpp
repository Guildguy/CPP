#include "ScalarConverter.hpp"

void	ScalarConverter::handleChar(const std::string& literal)
{
	char	c = literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::handleInt(const std::string& literal)
{
	long	n = std::strtol(literal.c_str(), NULL, 10);

	printChar(n);
	printInt(n);
	printFlt(n);
	printDbl(n);
}

void	ScalarConverter::handleFlt(const std::string& literal)
{
	float	f = static_cast<float>(std::strtod(literal.c_str(), NULL));

	printChar(f);
	printInt(f);
	printFlt(f);
	printDbl(f);
}

void	ScalarConverter::handleDbl(const std::string& literal)
{
	double	d = std::strtod(literal.c_str(), NULL);

	printChar(d);
	printInt(d);
	printFlt(d);
	printDbl(d);
}