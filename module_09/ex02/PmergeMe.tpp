#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include <iostream>

template<typename T>
void PmergeMe::sort(T& container)
{
	std::cout << "before: ";
	print(container);

	struct timespec before;
	clock_gettime(CLOCK_MONOTONIC_RAW, &before);

	merge_insertion_sort(container, 1);

	struct timespec after;
	clock_gettime(CLOCK_MONOTONIC_RAW, &after);
	after.tv_sec -= before.tv_sec;
	after.tv_nsec -= before.tv_nsec;

	std::cout << "after:  ";
	print(container);

	std::cout << "sort time: " << (after.tv_sec * 1000000) + (after.tv_nsec / 1000.0f) << "us\n";
}

template<typename T>
void PmergeMe::merge_insertion_sort(T& container, const int level)
{
	const int elem_size = 1 << (level - 1);
	const int value_offset = elem_size - 1;
	const int num_elements = container.size() / elem_size;
	const int num_pairs = num_elements / 2;
	const int num_pend = num_pairs + (num_elements % 2);

	//  INFO: sort pair elements
	for (int i = 0; i < num_pairs; ++i) {
		typename T::iterator pair = container.begin() + i * 2 * elem_size;
		if (pair[value_offset] > (pair + elem_size)[value_offset])
			std::swap_ranges(pair, pair + elem_size, pair + elem_size);
	}

	if (num_pairs > 1)
		merge_insertion_sort(container, level + 1);

	//  INFO: prepare pend and main
	for (int i = 1; i < num_pairs; ++i) {
		typename T::iterator a = container.begin() + (i * 2 + 1) * elem_size;
		for (int j = 0; j < i; ++j) {
			std::swap_ranges(a, a + elem_size, a - elem_size);
			a -= elem_size;
		}
	}

	//  INFO: insert pend elements
	int jacob_index = 0;
	int b_index = -1;
	int search_range;

	for (int i = 1; i < num_pend; ++i) {
		if (b_index < 0) {
			++jacob_index;
			b_index = jacobsthal(jacob_index) - jacobsthal(jacob_index - 1) - 1;
			search_range = (2 << jacob_index) - 1;
		}

		typename T::iterator b = container.begin() + std::min(num_pairs + i + b_index, num_elements - 1) * elem_size;
		typename T::iterator pos = binary_search(container.begin(), std::min(search_range, num_pairs + i), b[value_offset], elem_size);

		const int distance = std::distance(pos, b) / elem_size;
		for (int j = 0; j < distance; ++j) {
			std::swap_ranges(b, b + elem_size, b - elem_size);
			b -= elem_size;
		}

		--b_index;
	}
}

template<typename T>
T PmergeMe::binary_search(T first, const int range, const int value, const int elem_size)
{
	const int value_offset = elem_size - 1;

	int left = 0;
	int right = range - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		if ((first + (middle * elem_size))[value_offset] < value)
			left = middle + 1;
		else
			right = middle - 1;
	}

	return first + (left * elem_size);
}

template<typename T>
void PmergeMe::print(T& container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		if (it + 1 != container.end())
			std::cout << ' ';
	}
	std::cout << '\n';
}

#endif
