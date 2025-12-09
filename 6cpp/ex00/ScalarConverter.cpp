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

//
bool	ScalarConverter::isCharLiteral(const std::string& s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

bool	ScalarConverter::isIntLiteral(const std::string& i)
{
	size_t	n = 0;

	if (i[n] == '+' || i[n] == '-')
	    n++;
	if (n >= i.length())
	    return (false);

	while (n < i.length())
	{
	    if (!std::isdigit(i[n]))
	        return (false);
	    n++;
	}
	return (true);
}

bool	ScalarConverter::isFloatLiteral(const std::string& f)
{
	if (f[f.length() - 1] != 'f')
		return (false);

	size_t		n = 0;
	bool		dot = false;
	std::string	core = f.substr(0, f.length() - 1);

	if (core[n] == '+' || core[n] == '-')
		n++;

	if (n >= core.length())
		return (false);

	for (n; n < core.length(); n++)
	{
		if (core[n] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(core[n]))
			return (false);
	}
	return (dot);
}
bool	ScalarConverter::isDoubleLiteral(const std::string& d)
{
	bool	dot = false;
	size_t	n = 0;

	if (d[n] == '+' || d[n] == '-')
		n++;

	if (n >= d.length())
		return (false);

	for (n; n < d.length(); n++)
	{
		if (d[n] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(d[n]))
			return (false);
	}
	return (dot);
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

	std::cout << "char: ";
	if (std::isnan(convert) || std::isinf(convert) || convert < 0 || convert > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(convert)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(convert) << "'";
	std::cout << std::endl;
	/* ** */
	std::cout << "int: ";
	if (std::isnan(convert) || std::isinf(convert) ||
		convert < std::numeric_limits<int>::min() || convert > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(convert);
	std::cout << std::endl;
	/* ** */
	std::cout << "float: " << static_cast<float>(convert);
	if (convert - static_cast<int>(convert) == 0)
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
	/* ** */
	std::cout << "double: " << convert;
	if (convert - static_cast<int>(convert) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}
