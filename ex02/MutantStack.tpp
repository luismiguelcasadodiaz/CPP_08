
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void){}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void){}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const & other)
{
	(void)other;
}

template<typename T, typename Container>
MutantStack<T, Container> & MutantStack<T, Container>::operator=(MutantStack const & other)
{
	(void)other;
	return *this;
}

template<typename T, typename Container>
bool MutantStack<T, Container>::empty(void) const
{
	return this->c.empty();
}

template<typename T, typename Container>
size_t MutantStack<T, Container>::size(void) const
{
	return this->c.size();
}

template<typename T, typename Container>
T MutantStack<T, Container>::top(void)
{
	return std::stack<T, Container>::top();
}

template<typename T, typename Container>
void MutantStack<T, Container>::push(T const & type_value)
{
	std::stack<T, Container>::push(type_value);
}

template<typename T, typename Container>
void MutantStack<T, Container>::pop(void)
{
	std::stack<T, Container>::pop();
}
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}
//const_iterator begin() const;
//const_iterator end() const;
