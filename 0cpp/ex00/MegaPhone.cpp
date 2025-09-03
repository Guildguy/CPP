#include <iostream>
#include <string>
#include <cctype>

void	ft_upper(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << (char)std::toupper(str[i]);
}

int	main(int c, char **v)
{
	if (c > 1)
	{
		for (int i = 0; i < c - 1; i++)
		{
			ft_upper(v[i + 1]);
			if (i < c - 2)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
