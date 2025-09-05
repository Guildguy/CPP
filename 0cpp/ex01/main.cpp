#include "phonebook.hpp"

void	handleSignal(int sig)
{
	if (sig == SIGINT) {
        std::cerr << " Signal interrupt (Ctrl+C) detected." << std::endl;
        _exit(0);
    }
}

int	main(void)
{
	PhoneBook	Phonebook;
	Contact		NewContact;
	std::string	line;

	std::signal(SIGINT, handleSignal);
	while (6)
	{
		Phonebook.DisplayInfo();
		getline(std::cin, line);

		if (line == "ADD")
		{
			NewContact = Phonebook.CreateContact();
			Phonebook.Add(NewContact);
		}
		else if (line == "SEARCH")
			Phonebook.Search();
		else if (line == "EXIT")
		{
			std::cout << "See ya!" << std::endl;
			getline(std::cin, line);
			std::cout << "\033[2J\033[1;1H";
			break ;
		}
		else
		{
			std::cout << "Please, put a valid a command! read the commands above!" << std::endl;
			std::cout << "Type to continue..." << std::endl;
			getline(std::cin, line);
		}
		if (std::cin.eof())
		{
			std::cerr << "EOF detected!" << std::endl;
			break ;
		}
		std::cout << "\033[2J\033[1;1H";
	}
	return (0);
}
