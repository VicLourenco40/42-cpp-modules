#include "easyfind.hpp"

#include <iostream>
#include <vector>

int main(void)
{
	const int nums[4] = {1, 2, 3, 4};

	std::vector<int> v;
	v.reserve(4);
	v.insert(v.begin(), nums, nums + 4);

	std::cout << *easyfind(v, 2) << '\n';

	try
	{
		std::cout << *easyfind(v, 5) << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	const std::vector<int>& ref = v;

	std::cout << *easyfind(ref, 2) << '\n';

	try
	{
		std::cout << *easyfind(ref, 5) << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
