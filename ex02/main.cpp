#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe	sorter;

    try
	{
        sorter.parseTheInput(ac, av);

        std::cout << "Before: ";
        sorter.printVec();

        clock_t sVec = clock();
        std::vector<int> vec = sorter.mergeInsertAlgorithmVec(sorter.getVector());
        clock_t eVec = clock();

        clock_t sDeq = clock();
        std::deque<int> deq = sorter.mergeInsertAlgorithmDeq(sorter.getDeque());
        clock_t eDeq = clock();

        std::cout << "After: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        sorter.printProcessingTime(sVec, eVec, vec.size(), "vector");
        sorter.printProcessingTime(sDeq, eDeq, deq.size(), "deque");
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}
