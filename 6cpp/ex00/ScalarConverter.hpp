#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

class	ScalarConverter
{
	private:
		//CANONNICAL ORTODOXICAL FORM
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter&	operator=(const ScalarConverter& convert);
		~ScalarConverter();

		static bool	isCharLiteral(const std::string& s);
		static bool	isIntLiteral(const std::string& i);
	public:
		//AUX
		static void	convert(std::string& literal);
};

#endif