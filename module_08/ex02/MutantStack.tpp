#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return this->c.end();
}

#endif
