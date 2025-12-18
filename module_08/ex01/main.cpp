#include "Span.hpp"

#include <iostream>

int main(void)
{
	const int nums[] = {6, 3, 17, 9, 11};

	std::vector<int> vec;
	vec.reserve(5);
	vec.insert(vec.begin(), nums, nums + 5);

	{
		Span sp = Span(5);
		sp.addNumber(nums[0]);
		sp.addNumber(nums[1]);
		sp.addNumber(nums[2]);
		sp.addNumber(nums[3]);
		sp.addNumber(nums[4]);
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
		std::cout << '\n';
	}

	{
		Span sp = Span(5);
		sp.addNumbers(nums, nums + 5);
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
		std::cout << '\n';
	}

	{
		Span sp = Span(5);
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
		std::cout << '\n';
	}

	{
		Span sp = Span(2);
		try
		{
			sp.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		sp.addNumber(nums[0]);
		try
		{
			sp.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		sp.addNumber(nums[1]);
		std::cout << sp.shortestSpan() << '\n';
		try
		{
			sp.addNumber(nums[2]);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
}
