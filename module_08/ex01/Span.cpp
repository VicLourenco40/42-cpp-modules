#include "Span.hpp"

#include <algorithm>
#include <numeric>

Span::Span(void) : max(0) {}

Span::Span(const Span& other) : nums(other.nums), max(other.max) {}

Span::Span(unsigned int max) : max(max)
{
	nums.reserve(max);
}

Span::~Span(void) {}

void Span::addNumber(int num)
{
	if (nums.size() >= max)
		throw TooManyElementsException();

	nums.push_back(num);
}

unsigned int Span::shortestSpan(void) const
{
	if (nums.size() < 2)
		throw TooLittleElementsException();

	std::vector<int> copy = nums;
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), copy.begin());
	return *std::min_element(copy.begin() + 1, copy.end());
}

unsigned int Span::longestSpan(void) const
{
	if (nums.size() < 2)
		throw TooLittleElementsException();

	return *std::max_element(nums.begin(), nums.end()) -
		*std::min_element(nums.begin(), nums.end());
}

const char* Span::TooLittleElementsException::what(void) const throw()
{
	return "Too little elements";
}

const char* Span::TooManyElementsException::what(void) const throw()
{
	return "Too many elements";
}
