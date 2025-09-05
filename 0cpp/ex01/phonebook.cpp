#include "phonebook.hpp"

PhoneBook::PhoneBook() : Index(0), Counter(0)
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void    PhoneBook::DisplayInfo(void) {
    std::cout << "=======================================" << std::endl;
    std::cout << "|        This is your phonebook       |" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|  How to use:                        |" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|  ADD: Add a new contact             |" << std::endl;
    std::cout << "|  SEARCH: Search for a contact       |" << std::endl;
    std::cout << "|  EXIT: Exit the program             |" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|           Phonebook capacity: [" << Counter << "/8] |" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Command: ";
}

Contact PhoneBook::CreateContact(void)
{
	Contact		NewContact;
	std::string	line;

	std::cout << "First Name: ";
	getline(std::cin, line);
	NewContact.SetFirstName(line);
	
	std::cout << "Last Name: ";
	getline(std::cin, line);
	NewContact.SetLastName(line);
	
	std::cout << "Nick Name: ";
	getline(std::cin, line);
	NewContact.SetNickName(line);

	std::cout << "Phone Number: ";
	getline(std::cin, line);
	NewContact.SetPhoneNumber(line);

	std::cout << "Darkest Secret: ";
	getline(std::cin, line);
	NewContact.SetDarkestSecret(line);

	return (NewContact);
}

static bool Whitespace(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}

void	PhoneBook::Add(Contact NewContact)
{
	std::string line;

	if (Whitespace(NewContact.GetFirstName()) || Whitespace(NewContact.GetLastName()) || \
		Whitespace(NewContact.GetNickName()) || Whitespace(NewContact.GetPhoneNumber()) || \
		Whitespace(NewContact.GetDarkestSecret()))
	{
		std::cout << "Error: empty/whitespace or char in phone number field, please, try again" << std::endl;
		std::cout << "Type to continue..." << std::endl;
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
		contacts[Index] = NewContact;
		Index = (Index + 1) % 8; 
	}
}

void	PhoneBook::ContactListInfo(void)
{
	std::cout << "|" << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nick Name" << "|" << std::endl;
}
 
void	PhoneBook::SearchContactsByIndex()
{
	std::string			line;
	int					index;
	Contact				indexed;
	
	std::cout << std::endl << "Enter index to display contact: " << std::endl;
	getline(std::cin, line);

	std::stringstream	parser(line);
	parser >> index;
	if (parser.fail())
		index = 0;
	if (index >= 1 && index <= Counter)
	{
		indexed = contacts[index - 1];
		std::cout << "First Name: " << indexed.GetFirstName() << std::endl;
		std::cout << "Last Name: " << indexed.GetLastName() << std::endl;
		std::cout << "Nick Name: " << indexed.GetNickName() << std::endl;
		std::cout << "Phone Number: " << indexed.GetPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << indexed.GetDarkestSecret() << std::endl;
	}
	else
		std::cerr << "Invalid index!" << std::endl;
	
	std::cout << "Type to continue..." << std::endl;
	getline(std::cin, line);
}

void	PhoneBook::Search(void)
{
	std::string	line;

	if (Counter == 0)
	{
		std::cout << "Your phonebook is empty. Use ADD to add a contact." << std::endl;
		std::cout << "Type to continue..." << std::endl;
		getline(std::cin, line);
		return ;
    }

	ContactListInfo();

	for(int i = 0; i < Counter; i++)
	{
		std::string FirstName = contacts[i].GetFirstName();
		if (FirstName.length() > 10)
			FirstName = FirstName.substr(0, 9) + ".";
		std::string LastName = contacts[i].GetLastName();
		if (LastName.length() > 10)
			LastName = LastName.substr(0, 9) + ".";
		std::string NickName = contacts[i].GetNickName();
		if (NickName.length() > 10)
			NickName = NickName.substr(0, 9) + ".";

		/*std::cout << std::setw(10);
		std::cout << std::right;*/

        std::cout << "|" << std::setw(10) << std::right << (i + 1);
        std::cout << "|" << std::setw(10) << std::right << FirstName;
        std::cout << "|"  << std::setw(10) << std::right << LastName;
        std::cout << "|"  << std::setw(10) << std::right << NickName << "|" << std::endl;
	}
	SearchContactsByIndex();
}
