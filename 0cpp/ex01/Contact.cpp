#include "Contact.hpp"

/************************************************ constructor definition *************************************************/
Contact::Contact()
{
	return ;
}

/************************************************ destructor definition *************************************************/
Contact::~Contact()
{
	return ;
}

/************************************************ Getter definition *************************************************/
std::string Contact::GetFirstName()
{
	return (FirstName);
}

std::string Contact::GetLastName()
{
	return (LastName);
}

std::string Contact::GetNickName()
{
	return (NickName);
}

std::string Contact::GetPhoneNumber()
{
	return (PhoneNumber);
}

std::string Contact::GetDarkestSecret()
{
	return (DarkestSecret);
}

/************************************************ Setter definition *************************************************/
void	Contact::SetFirstName(const std::string& SetFirstName)
{
	this->FirstName = SetFirstName;
}

void	Contact::SetLastName(const std::string& SetLastName)
{
	this->LastName = SetLastName;
}

void	Contact::SetNickName(const std::string& SetNickName)
{
	this->NickName = SetNickName;
}

void	Contact::SetPhoneNumber(const std::string& SetPhoneNumber)
{
	this->PhoneNumber = SetPhoneNumber;
}

void	Contact::SetDarkestSecret(const std::string& SetDarkestSecret)
{
	this->DarkestSecret = SetDarkestSecret;
}

/*void	displayPhonebook(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|  index:  |   name:  |   last:  |   nick:  |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}*/