//CANONNICAL ORTODOXICAL FORM
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : 
std::stack<T, Container>()
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &copy) : 
std::stack<T, Container>(copy)
{}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, 
Container>::operator=(const MutantStack &stack)
{
    std::stack<T, Container>::operator=(stack);
    return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}
