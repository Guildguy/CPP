#include "Sed.hpp"

int	main(int c, char **v)
{
	if (c != 4)
	{
		std::cerr << "Error: Type ./Sed_is_for_loosers <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	Sed	file(v[1], v[2], v[3]);
	file.Replace();

	return (0);
}
