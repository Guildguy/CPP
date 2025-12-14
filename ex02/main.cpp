#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe	sorter;

    try
	{
        sorter.parseTheInput(ac, av);

        std::cout << "Before: ";
        sorter.printVec();
        std::vector<int> vec = sorter.mergeInsertAlgorithmVec(sorter.getVector());
        std::cout << "After: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        sorter.mergeInsertAlgorithmDeq(sorter.getDeque());
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}

/*
1. Divide em pares (winner e loser)
2. Ordena winner recursivamente
3. Insere cada elemento de loser com busca binária
*/