#include "contact.hpp"

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
	for (size_t i = 0; i < SetPhoneNumber.length(); i++)
	{
		if (i == 0 && SetPhoneNumber[i] == '+')
			continue;
		if (!std::isdigit(SetPhoneNumber[i]))
		{
			std::cout << "-> Invalid character in phone number. Only digits and a leading '+' are allowed." << std::endl;
			this->PhoneNumber = "";
			return ;
		}
	}
	this->PhoneNumber = SetPhoneNumber;
}

void	Contact::SetDarkestSecret(const std::string& SetDarkestSecret)
{
	this->DarkestSecret = SetDarkestSecret;
}
