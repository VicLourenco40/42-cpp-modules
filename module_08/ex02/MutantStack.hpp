#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename
		MutantStack<T>::container_type::iterator iterator;
	typedef typename
		MutantStack<T>::container_type::const_iterator const_iterator;

	iterator begin(void);
	const_iterator begin(void) const;

	iterator end(void);
	const_iterator end(void) const;
};

#include "MutantStack.tpp"

#endif
