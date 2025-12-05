#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class	Bureaucrat
{
	private:
		const std::string	name;
		int 				grade;
	public:
		Bureaucrat(); //std constructor

		Bureaucrat(const std::string name, int grade);

		~Bureaucrat(); //destructor

		Bureaucrat(const Bureaucrat &copy); //copy constructor

		Bureaucrat&	operator=(const	Bureaucrat &bureaucrat); //copy assignment operator

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

		int					getGrade() const;
		const std::string	getName() const;

		void				increment(); //--
		void				decrement(); //++
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif