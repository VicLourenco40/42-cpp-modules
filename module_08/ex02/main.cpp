#include "MutantStack.hpp"

#include <iostream>

int main()
{
	MutantStack<int> ms;

	std::cout << ms.size() << '\n';
	ms.push(5);
	ms.push(17);
	std::cout << ms.size() << ' ' << ms.top() << '\n';
	ms.pop();
	std::cout << ms.size() << ' ' << ms.top() << '\n';
	std::cout << '\n';

	ms.push(3);
	ms.push(6);
	ms.push(0);
	ms.push(737);

	const MutantStack<int>& cref = ms;
	MutantStack<int>::const_iterator cit = cref.begin();
	MutantStack<int>::const_iterator cite = cref.end();

	for (; cit != cite; cit++)
	{
		//*cit += 1000;
		std::cout << *cit << '\n';
	}
	std::cout << '\n';

	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();

	++it;
	--it;

	for (; it != ite; it++)
	{
		*it += 1000;
		std::cout << *it << '\n';
	}
	std::cout << '\n';

	std::stack<int> s(ms);
	std::cout << ms.size() << ' ' << ms.top() << '\n';
	std::cout << s.size() << ' ' << s.top() << '\n';
}
