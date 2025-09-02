#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contacts.hpp"

class Phonebook
{
	private:
		char	contacts[8];
		int 	index;
		int 	counter;
		int 	n_index;
	
	public:
		Phonebook();
		~Phonebook();

};

#endif