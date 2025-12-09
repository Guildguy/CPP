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

		//DETECTORS
		static bool	isCharLiteral(const std::string& c);
		static bool	isIntLiteral(const std::string& i);
		static bool	isFloatLiteral(const std::string& f);
		static bool	isDoubleLiteral(const std::string& d);
		static bool	isPseudoLiteral(const std::string& l);

		//PRINTERS
		static void	printChar(double c);
		static void	printInt(double i);
		static void	printFlt(double f);
		static void	printDbl(double d);
		static void handlePseudoLiteral(const std::string& l);
	public:
		//AUX
		static void	convert(std::string& literal);
};

#endif