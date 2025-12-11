#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T> class	Array
{
	private:
		T*				_data;
		unsigned int	_size;
	public:
		//CANONNICAL ORTODOXICAL FORM
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array&	operator=(const Array& arr);
		~Array();

		//OVERLOAD
		T&				operator[](unsigned int i); //write overload
		const T&		operator[](unsigned int i) const; //read oveload

		//AUX
		unsigned int	size(void) const;

		class	OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index out of bounds");
				}
		};
};

#include "Template.tpp"

#endif
