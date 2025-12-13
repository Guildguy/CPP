#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <ctime>
#include <exception>

class Span
{
	private:
		unsigned int	_N;
		std::vector<int> _vec;
	public:
		//CANONNICAL ORTODOXICAL FORM
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span&	operator=(const Span& span);
		~Span();

		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		//AUX
		void			addNumber(int n); //adds a single nbr
		int				shortestSpan();
		int				longestSpan();
};

#endif