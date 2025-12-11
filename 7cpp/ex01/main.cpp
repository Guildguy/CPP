#include "iter.hpp"

int main()
{
	int			arrayI[] = {1, 2, 3, 4};
	const char	arrayC[] = {'A', 'B', 'C', 'D'};

	std::cout << "Printing an INT array" << std::endl;
	::iter(arrayI, 4, addOne);

	::iter(arrayI, 4, printOnCPP);

	std::cout << "\nPrinting an CHAR array" << std::endl;
	::iter(arrayC, 2, printOnCPP);

	return (0);
}
