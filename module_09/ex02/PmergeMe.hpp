#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
private:
	PmergeMe(void);
	PmergeMe(const PmergeMe& other);

	PmergeMe& operator=(const PmergeMe& other);

	template<typename T>
	static void merge_insertion_sort(T& container, int level);

	template<typename T>
	static T binary_search(T first, int range, int value, int elem_size);

	template<typename T>
	static void print(T& container);

	static int jacobsthal(int index);

public:
	~PmergeMe(void);

	template<typename T>
	static void sort(T& container);
};

#include "PmergeMe.tpp"

#endif
