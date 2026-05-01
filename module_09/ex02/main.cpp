#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <deque>

#include <cstdlib>

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "usage: PmergeMe <int>...\n";
		return 1;
	}

	std::vector<int> vector;
	std::deque<int> deque;

	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		if (num < 0) {
			std::cerr << "error: negative number\n";
			return 1;
		}
		vector.push_back(num);
		deque.push_back(num);
	}

	std::cout << "std::vector<int>\n";
	PmergeMe::sort(vector);

	std::cout << "\nstd::deque<int>\n";
	PmergeMe::sort(deque);
}
