#include "ScalarConverter.hpp"

//DETECTORS
bool	ScalarConverter::isCharLiteral(const std::string& c)
{
	return (c.length() == 1 && !std::isdigit(c[0]));
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

bool	ScalarConverter::isPseudoLiteral(const std::string& l)
{
	return
	(
		l == "nan"  || l == "+inf" || l == "-inf" ||
		l == "nanf" || l == "+inff" || l == "-inff"
	);
}
