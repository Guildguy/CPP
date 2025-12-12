#include "Span.hpp"

//CANONNICAL ORTODOXICAL FORM
Span::Span(): 
_N(0) {};

Span::Span(unsigned int i): _N(i) {};

Span::Span(const Span &copy):
_N(copy._N),
_vec(copy._vec)
{};

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return *this;
	_vec = span._vec;
	_N = span._N; 
	return *this;
}

Span::~Span(){};

//AUX
void Span::addNumber(int i)
{
	if (_vec.size() >= _N)
		throw std::overflow_error("Error! Span is full");
	_vec.push_back(i);
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw std::length_error("Not enough numbers!");
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int minSpan = INT_MAX;
	for (size_t i = 0; i < tmp.size() - 1; ++i)
	{
		int	span = tmp[i + 1] - tmp[i];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int	Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw std::length_error("Not enough numbers!");
	int minVal = *std::min_element(_vec.begin(), _vec.end());
	int maxVal = *std::max_element(_vec.begin(), _vec.end());
	return (maxVal - minVal);
}
