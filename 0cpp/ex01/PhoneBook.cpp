#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : Index(0), Counter(0), NIndex(0)
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

Contact PhoneBook::CreateContact(void)
{
	Contact		NewContact;
	std::string	line;

	std::cout << "First Name:";
	getline(std::cin, line);
	NewContact.SetFirstName(line);
	
	std::cout << "Last Name:";
	getline(std::cin, line);
	NewContact.SetLastName(line);
	
	std::cout << "Nick Name:";
	getline(std::cin, line);
	NewContact.SetNickName(line);

	std::cout << "Phone Number:";
	getline(std::cin, line);
	NewContact.SetPhoneNumber(line);

	std::cout << "Darkest Secret:";
	getline(std::cin, line);
	NewContact.SetDarkestSecret(line);

	return (NewContact);
}

void	PhoneBook::add(Contact NewContact)
{
	std::string line;

	if (NewContact.GetFirstName().empty() || NewContact.GetLastName().empty() || \
		NewContact.GetNickName().empty() || NewContact.GetPhoneNumber().empty() || \
		NewContact.GetDarkestSecret().empty())
	{
		std::cout << "Error: empty field, please, try again" << std::endl;
		getline(std::cin, line);
		return ;
	}
	if (Counter < 8)
	{
		contacts[Counter] = NewContact;
		Counter++;
	}
	else if (Counter == 8)
	{
		contacts[NIndex] = NewContact;
		NIndex = (NIndex + 1) % 8; 
	}
	
}
