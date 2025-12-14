#include "PmergeMe.hpp"

PmergeMe::PmergeMe() :
n_vec(),
n_deq()
{}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& merge)
{
	if (this != &merge)
	{
		this->n_vec = merge.n_vec;
		this->n_deq = merge.n_deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

//AUX
void PmergeMe::parseTheInput(int ac, char **av)
{
    if (ac < 2)
        throw std::invalid_argument("Error: No sequence provided");

    for (int n = 1; n < ac; n++)
	{
        std::string	arg = av[n];

        if (arg.empty())
			continue;

        for (size_t i = 0; i < arg.size(); i++)
		{
            if (!isdigit(arg[i]))
                throw std::invalid_argument("Error: Invalid number (only positive integers)");
        }

        long	value = std::atol(arg.c_str());

        if (value > INT_MAX) 
            throw std::invalid_argument("Error: Number too large");

		if (std::find(n_vec.begin(), n_vec.end(), value) != n_vec.end())
            throw std::invalid_argument("Error: Duplicate number");
		
        n_vec.push_back(static_cast<int>(value));
        n_deq.push_back(static_cast<int>(value));
    }
	if (n_vec.empty() || n_deq.empty())
		throw std::invalid_argument("Error: No valid numbers provided");
}

void	PmergeMe::printVec()
{
	for (std::vector<int>::iterator it = n_vec.begin(); it != n_vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printDeq()
{
	for (std::deque<int>::iterator it = n_deq.begin(); it != n_deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//GETTER
std::vector<int>	PmergeMe::getVector() const
{
	return (this->n_vec);
}

std::deque<int>	PmergeMe::getDeque() const
{
	return (this->n_deq);
}

//ALGORITHM
std::vector<int>	PmergeMe::JacobSthalSequence(int limit)
{
	std::vector<int>	sequence;
	int					next;
	int					n1 = 1, n2 = 1, temp;

	while (n2 < limit)
	{
		sequence.push_back(n2);
		next = n2 + (2 * n1);
		temp = n2;
		n2 = next;
		n1 = temp;
	}
	return (sequence);
}


//VECTOR
void	PmergeMe::splitPairsVec(const std::vector<int>& vec, std::vector<int>& winner, std::vector<int>& loser)
{
    std::vector<int>::const_iterator	it = vec.begin();

    while (it != vec.end()) //defines the winner n' loser array
    {
        if (it + 1 != vec.end())
        {
            if (*it > *(it + 1))
            {
                winner.push_back(*it);
                loser.push_back(*(it + 1));
            }
            else
            {
                winner.push_back(*(it + 1));
                loser.push_back(*it);
            }
            it += 2;
        }
        else
        {
            loser.push_back(*it);
            ++it;
        }
    }
}

void	PmergeMe::binaryInsertVec(std::vector<int>& winner, int value)
{
    int start = 0;
    int end = winner.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (winner[mid] < value)
            start = mid + 1;
        else
            end = mid;
    }
    winner.insert(winner.begin() + start, value);
}

void	PmergeMe::insertLosersVec(std::vector<int>& winner, const std::vector<int>& loser)
{
    std::vector<int> jacobSeq = JacobSthalSequence(loser.size());
    std::vector<bool> inserted(loser.size(), false);

    for (size_t i = 0; i < jacobSeq.size(); ++i)
    {
        int id = jacobSeq[i];
        if (id < static_cast<int>(loser.size()))
        {
            binaryInsertVec(winner, loser[id]);
            inserted[id] = true;
        }
    }
    for (size_t i = 0; i < loser.size(); ++i)
    {
        if (!inserted[i])
            binaryInsertVec(winner, loser[i]);
    }
}

std::vector<int>	PmergeMe::mergeInsertAlgorithmVec(std::vector<int> vec)
{
	if (vec.size() <= 1)
		return (vec);
	
	std::vector<int>			winner;
	std::vector<int>			loser;

	splitPairsVec(vec, winner, loser);
	winner = mergeInsertAlgorithmVec(winner);
	insertLosersVec(winner, loser);

	return (winner);
}

//DEQUE
void	PmergeMe::splitPairsDeq(const std::deque<int>& deq, std::deque<int>& winner, std::deque<int>& loser)
{
    std::deque<int>::const_iterator	it = deq.begin();

    while (it != deq.end()) //defines the winner n' loser array
    {
        if (it + 1 != deq.end())
        {
            if (*it > *(it + 1))
            {
                winner.push_back(*it);
                loser.push_back(*(it + 1));
            }
            else
            {
                winner.push_back(*(it + 1));
                loser.push_back(*it);
            }
            it += 2;
        }
        else
        {
            loser.push_back(*it);
            ++it;
        }
    }
}

void	PmergeMe::binaryInsertDeq(std::deque<int>& winner, int value)
{
    int start = 0;
    int end = winner.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (winner[mid] < value)
            start = mid + 1;
        else
            end = mid;
    }
    winner.insert(winner.begin() + start, value);
}

void	PmergeMe::insertLosersDeq(std::deque<int>& winner, const std::deque<int>& loser)
{
    std::vector<int> jacobSeq = JacobSthalSequence(loser.size());
    std::vector<bool> inserted(loser.size(), false);

    for (size_t i = 0; i < jacobSeq.size(); ++i)
    {
        int id = jacobSeq[i];
        if (id < static_cast<int>(loser.size()))
        {
            binaryInsertDeq(winner, loser[id]);
            inserted[id] = true;
        }
    }
    for (size_t i = 0; i < loser.size(); ++i)
    {
        if (!inserted[i])
            binaryInsertDeq(winner, loser[i]);
    }
}

std::deque<int>		PmergeMe::mergeInsertAlgorithmDeq(std::deque<int> deq)
{
	if (deq.size() <= 1)
		return (deq);
	
	std::deque<int>			winner;
	std::deque<int>			loser;

	splitPairsDeq(deq, winner, loser);
	winner = mergeInsertAlgorithmDeq(winner);
	insertLosersDeq(winner, loser);

	return (winner);
}


