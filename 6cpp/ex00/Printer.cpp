#include "ScalarConverter.hpp"

//PRINTERS
void	ScalarConverter::printChar(double c)
{
	std::cout << "char: ";
	if (std::isnan(c) || std::isinf(c) || c < 0 || c > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(c)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(c) << "'";
	std::cout << 
	std::endl;
}

void	ScalarConverter::printInt(double i)
{
	std::cout << "int: ";
	if (std::isnan(i) || std::isinf(i) ||
		i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(i);
	std::cout << std::endl;
}

void	ScalarConverter::printFlt(double f)
{
	float	flt = static_cast<float>(f);

	std::cout << "float: " << flt;
	if (!std::isnan(f) && !std::isinf(f) && (flt - static_cast<int>(flt) == 0))
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
}

void	ScalarConverter::printDbl(double d)
{
	std::cout << "double: " << convert;
	if (!std::isnan(d) && !std::isinf(d) && (d - static_cast<int>(d) == 0))
		std::cout << ".0";
	std::cout << std::endl;
}
