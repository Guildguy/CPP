#include "Span.hpp"

int main()
{
	//using addNumber(const int);
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "=== Small Test ===" << std::endl;
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span:  " << sp.longestSpan() << std::endl;

	//using addNumber(It begin, It end);
	const int	SIZE = 10000;

	Span SP(SIZE);
	std::vector<int> rNumbers;
	rNumbers.reserve(SIZE);

	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < SIZE; ++i)
		rNumbers.push_back(std::rand());

	SP.addNumber(rNumbers.begin(), rNumbers.end());

	std::cout << "\n=== Large Test (10,000 numbers) ===" << std::endl;
	std::cout << "Shortest Span: " << SP.shortestSpan() << std::endl;
	std::cout << "Longest Span:  " << SP.longestSpan() << std::endl;

	return (0);
}
