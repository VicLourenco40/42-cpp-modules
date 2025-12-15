#include "iter.hpp"

int main(void)
{
	int nums[] = {1, 2, 3, 4};
	iter(nums, 4, print);
	std::cout << '\n';
	iter(nums, 4, increment);
	iter(nums, 4, print);
	std::cout << '\n';

	const char chars[] = {'a', 'b', 'c', 'd'};
	iter(chars, 4, print);
	//iter(chars, 4, increment);
}
