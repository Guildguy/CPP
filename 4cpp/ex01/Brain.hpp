#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	protected:
		std::string	ideias[100];

	public:
		Brain();
		~Brain();

		Brain(const Brain& copy);
		
		Brain&	operator=(const Brain& Brain);
};

#endif