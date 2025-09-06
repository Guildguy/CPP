#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <csignal>
# include "Contact.hpp"

class Phonebook
{
	private:
		Contact	contacts[8];
		int 	Index;
		int 	Counter;
	
	public:
		Phonebook();
		~Phonebook();

		void	DisplayInfo();
		Contact	CreateContact();
		void	Add(Contact NewContact);
		void	ContactListInfo();
		void	SearchContactsByIndex();
		void	Search();
};

#endif
