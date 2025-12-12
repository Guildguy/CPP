template <typename T>
typename T::iterator	easyfind(T& container, int val)
{
	typename T::iterator Itr = std::find(container.begin(), container.end(), val);
	if (Itr == container.end())
		throw std::runtime_error("Value not found!");
	return (Itr);
}
