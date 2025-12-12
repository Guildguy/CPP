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

		//TEMPLATE
		template<typename It>
		void			addNumber(It begin, It end) //adds a range of nbrs
		{
			if (_vec.size() + std::distance(begin, end) > _N)
						throw std::out_of_range("Not enough space in Span!");
			_vec.insert(_vec.end(), begin, end);
		}

		//AUX
		void			addNumber(int n); //adds a single nbr
		int				shortestSpan();
		int				longestSpan();
};

#endif