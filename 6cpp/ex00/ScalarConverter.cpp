#include	"ScalarConverter.hpp"

//CANONNICAL ORTODOXICAL FORM
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& convert)
{
	(void)convert; return *this;
}

ScalarConverter::~ScalarConverter() {}

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

void	ScalarConverter::convert(std::string& literal)
{
	if (isCharLiteral(literal))
	{
		char	c = literal[0];

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

		return ;
	}

	if (isIntLiteral(literal))
	{
		long	n = std::strtol(literal.c_str(), NULL, 10);

		std::cout << "char: ";
		if (n < 0 || n > 127)
		    std::cout << "impossible";
		else if (!std::isprint(static_cast<char>(n)))
		    std::cout << "Non displayable";
		else
		    std::cout << "'" << static_cast<char>(n) << "'";

		std::cout << std::endl
		;
		std::cout << "int: " << static_cast<int>(n) << std::endl;

		std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;

		std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;

		return ;
	}

	if (isFloatLiteral(literal))
	{
		float	f = static_cast<float>(std::strtod(literal.c_str(), NULL));
		double	d = static_cast<double>(f);
		
		std::cout << "char: ";
		if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
			std::cout << "impossible";
		else if (!std::isprint(static_cast<char>(f)))
			std::cout << "Non displayable";
		else
			std::cout << "'" << static_cast<char>(f) << "'";
		std::cout << std::endl;	
		
		std::cout << "int: ";
		if (std::isnan(f) || std::isinf(f) ||
			f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(f);
		std::cout << std::endl;

		std::cout << "float: " << f;
		if (f - static_cast<int>(f) == 0)
			std::cout << ".0f";
		else
			std::cout << "f";
		std::cout << std::endl;

		std::cout << "double: " << d;
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0";
		std::cout << std::endl;	
		
		return ;
	}

	if (isDoubleLiteral(literal))
	{
		double	d = std::strtod(literal.c_str(), NULL);
		float	f = static_cast<float>(d);

		std::cout << "char: ";
		if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
			std::cout << "impossible";
		else if (!std::isprint(static_cast<char>(d)))
			std::cout << "Non displayable";
		else
			std::cout << "'" << static_cast<char>(d) << "'";
		std::cout << std::endl;
		
		std::cout << "int: ";
		if (std::isnan(d) || std::isinf(d) ||
			d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(d);
			std::cout << std::endl;

		std::cout << "float: " << f;
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0f";
		else
			std::cout << "f";
		std::cout << std::endl;
		
		std::cout << "double: " << d;
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0";
		std::cout << std::endl;
		return ;
	}

	if (isPseudoLiteral(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (literal == "nan" || literal == "+inf" || literal == "-inf")
		{
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		else
		{
			std::string core = literal.substr(0, literal.length() - 1);
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << core << std::endl;
		}		
		return ;
	}

	char	*end;
	double	convert = std::strtod(literal.c_str(), &end);

	if (*end != '\0' && std::string(end) != "f")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	printChar(convert);
	/* ** */
	printInt(convert);
	/* ** */
	printFlt(convert);
	/* ** */
	printDbl(convert);
}
