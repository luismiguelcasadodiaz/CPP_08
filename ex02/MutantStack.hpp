#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <cstddef>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T , Container>
{
    public:
        MutantStack(void);
        ~MutantStack(void);
        MutantStack(MutantStack const & other);
        MutantStack & operator=(MutantStack const & other);
		bool empty(void) const;
		size_t size(void) const;
		T top(void);

		void push(T const & type_value);
		void pop(void);
		typedef typename Container::iterator iterator ;
		typedef typename Container::const_iterator const_iterator ;        
        iterator begin();
        iterator end();
        //const_iterator begin() const;
        //const_iterator end() const;
};
#include "MutantStack.tpp"
#endif
