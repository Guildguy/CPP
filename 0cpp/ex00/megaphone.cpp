#include "iostream"

void	ft_upper(std::string str)
{
	char up;
	for (int i = 0; i < (int)str.length(); i++)
	{
		up = (char)std::toupper(str[i]);
		std::cout << up;
	}
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