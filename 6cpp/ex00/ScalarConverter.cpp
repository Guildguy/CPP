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

//AUX
void	ScalarConverter::convert(std::string& literal)
{
	if (isCharLiteral(literal))
		return (handleChar(literal));
	if (isIntLiteral(literal))
		return (handleInt(literal));
	if (isFloatLiteral(literal))
		return (handleFlt(literal));
	if (isPseudoLiteral(literal))
		return (handlePseudoLiteral(literal));
	if (isDoubleLiteral(literal))
		return (handleDbl(literal));

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return ;
}
