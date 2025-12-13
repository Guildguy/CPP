#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		//CANONNICAL ORTODOXICAL FORM
		MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &stack);
		~MutantStack();

		//
		typedef typename Container::iterator					iterator;
		typedef typename Container::const_iterator				const_iterator;
		typedef typename Container::reverse_iterator			reverse_iterator;
		typedef typename Container::const_reverse_iterator		const_reverse_iterator;

		//IT
		iterator	begin()
		{
			return (this->c.begin());
		}
		
		iterator	end()
		{ 
			return (this->c.end());
		}

		//CONST IT
		const_iterator	begin() const
		{
			return (this->c.begin());
		}

		const_iterator	end() const
		{
			return (this->c.end());
		}

		//REV IT
		reverse_iterator	rbegin()
		{
			return (this->c.rbegin());
		}
		
		reverse_iterator	rend()
		{
			return (this->c.rend());
		}

		//CONST REV IT
		const_reverse_iterator	rbegin() const
		{
			return (this->c.rbegin());
		}

		const_reverse_iterator	rend() const
		{
			return (this->c.rend());
		}
};

#include "MutantStack.tpp"

#endif
