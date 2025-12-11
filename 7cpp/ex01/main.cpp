#include "iter.hpp"

int main()
{
	int	array[] = {1, 2, 3, 4};

	::iter(array, 4, addOne);

	::iter(array, 4, print<int>);

	return (0);
}
