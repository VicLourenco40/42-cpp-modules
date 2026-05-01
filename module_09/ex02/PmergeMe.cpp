#include "PmergeMe.hpp"

#include <algorithm>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe(void) {}

int PmergeMe::jacobsthal(int index)
{
	int a = 1;
	int b = 3;

	if (index <= 0)
		return a;

	for (; index > 1; --index) {
		a = a * 2 + b;
		std::swap(a, b);
	}

	return b;
}
