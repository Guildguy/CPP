#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <exception>
#include <set>
#include <ctime>
#include <climits>
#include <iomanip>
#include <algorithm> 

class	PmergeMe
{
	private:
		std::vector<int>	n_vec;
        std::deque<int>		n_deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator=(const PmergeMe& merge);
		~PmergeMe();

		//AUX
		void	parseTheInput(int ac, char **av);
		void	printVec();
		void	printDeq();

		//GETTER
		std::vector<int>	getVector() const;
		std::deque<int>		getDeque() const;

		//ALGORITHM
		std::vector<int>	JacobSthalSequence(int limit);
		void 				splitPairsVec(const std::vector<int>& vec, std::vector<int>& winner, std::vector<int>& loser);
		void				binaryInsertVec(std::vector<int>& winner, int value);
		void				insertLosersVec(std::vector<int>& winner, const std::vector<int>& loser);



		std::vector<int>	mergeInsertAlgorithmVec(std::vector<int> vec);

		void 				splitPairsDeq(const std::deque<int>& deq, std::deque<int>& winner, std::deque<int>& loser);
		void				binaryInsertDeq(std::deque<int>& winner, int value);
		void				insertLosersDeq(std::deque<int>& winner, const std::deque<int>& loser);

		std::deque<int>		mergeInsertAlgorithmDeq(std::deque<int> deq);

};

#endif