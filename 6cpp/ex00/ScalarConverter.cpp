#include	"ScalarConverter.hpp"

//static_cast<type>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& convert) {}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char	c = literal[0];

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

		return ;
	}
	else
	{
		double	dConvert = strtod(&literal);
	}
}