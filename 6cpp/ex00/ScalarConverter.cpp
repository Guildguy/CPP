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
		char	*end;
		double	dConvert = std::strtod(literal.c_str(), &end);

		if (*end != '\0' && std::string(end) != "f")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}

		std::cout << "char: ";
		if (std::isnan(dConvert) || std::isinf(dConvert) || dConvert < 0 || dConvert > 127)
			std::cout << "impossible";
		else if (!std::isprint(static_cast<char>(dConvert)))
			std::cout << "Non displayable";
		else
			std::cout << "'" << static_cast<char>(dConvert) << "'";
		std::cout << std::endl;

		std::cout << "int: ";
		if (std::isnan(dConvert) || std::isinf(dConvert) || 
			dConvert < std::numeric_limits<int>::min() || dConvert > std::numeric_limits<int>::max())
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(dConvert);
		std::cout << std::endl;

		std::cout << "float: " << static_cast<float>(dConvert);
		if (dConvert - static_cast<int>(dConvert) == 0) 
			std::cout << ".0f"; 
		else 
			std::cout << "f";
		std::cout << std::endl;

		std::cout << "double: " << dConvert;
		if (dConvert - static_cast<int>(dConvert) == 0) 
			std::cout << ".0";
		std::cout << std::endl;
	}
}
