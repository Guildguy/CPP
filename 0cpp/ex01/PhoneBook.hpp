#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int 	Index;
		int 	Counter;
		int 	NIndex;
	
	public:
		PhoneBook();
		~PhoneBook();

		Contact	CreateContact();
		void	add(Contact NewContact);
		

};

#endif