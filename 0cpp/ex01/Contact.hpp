#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	private: //all below is atribute
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
	
	public: //the way we access the private is w/ public
		Contact(); //constructor
		~Contact(); //destructor

//		getter function declaration
		std::string	GetFirstName();
		std::string	GetLastName();
		std::string	GetNickName();
		std::string	GetPhoneNumber();
		std::string	GetDarkestSecret();

//		setter function declaration
		void	SetFirstName(const std::string& SetFirstName);
		void	SetLastName(const std::string& SetLastName);
		void	SetNickName(const std::string& SetNickName);
		void	SetPhoneNumber(const std::string& SetPhoneNumber);
		void	SetDarkestSecret(const std::string& SetDarkestSecret);
};

#endif
