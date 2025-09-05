#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <csignal>
# include "contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int 	Index;
		int 	Counter;
	
	public:
		PhoneBook();
		~PhoneBook();

		void	DisplayInfo();
		Contact	CreateContact();
		void	Add(Contact NewContact);
		void	ContactListInfo();
		void	SearchContactsByIndex();
		void	Search();
};

#endif
