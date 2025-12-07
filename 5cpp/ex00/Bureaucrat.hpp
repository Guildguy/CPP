#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	private:
		const std::string	name;
		int 				grade;
	public:
		//CANONNICAL ORTODOXICAL FORM
		Bureaucrat(); //std constructor
		Bureaucrat(const std::string name, int grade); //constructor w/ parameters
		Bureaucrat(const Bureaucrat &copy); //copy constructor
		Bureaucrat&	operator=(const	Bureaucrat &bureaucrat); //copy assignment operator
		~Bureaucrat(); //destructor

		//GETTERS
		int					getGrade() const;
		const std::string	getName() const;

		//AUX
		void				increment(); //--
		void				decrement(); //++

		//EXCEPTION HANDLER
		class	GradeTooLowException : public std::exception //exceptions
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooHighException : public std::exception //exceptions
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
