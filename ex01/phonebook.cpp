#include "phonebook.hpp"

int	main(int c, char **v)
{
	char f_name[100], l_name[100], n_name[100], dark_s[500];
	int  p_nbr;

	if (c == 1)
	{
		std::cout << "Welcome to the Phonebook!" << std::endl;
		std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	}
	if (c == 2)
		{
			if (std::string(v[1]) == "SEARCH")
			{
				displayPhonebook();
				std::cout << "No contacts found. Please add contacts using 'ADD' command." << std::endl;
				return (0);
			}
			if (std::string(v[1]) == "EXIT")
			{
				std::cout << "Exiting the phonebook. Goodbye!" << std::endl;
				return (0);
			}
			if (std::string(v[1]) == "ADD")
			{
				std::cout << "Enter first name: ";
				std::cin >> f_name;

				std::cout << "Enter last name: ";
				std::cin >> l_name;

				std::cout << "Enter nickname: ";
				std::cin >> n_name;

				std::cout << "Enter phone number: ";
				std::cin >> p_nbr;

				std::cout << "Enter darkest secret: ";
				std::cin >> dark_s;

				std::cout << "Contact added successfully!" << std::endl;
			}
			else
				std::cout << "Invalid command. Use 'ADD' to add a contact." << std::endl;
		}
}