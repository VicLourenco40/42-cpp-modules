#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	std::vector<int> nums;
	unsigned int max;

	Span(void);

public:
	Span(const Span& other);
	Span(unsigned int max);
	~Span(void);

	void addNumber(int num);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

	template<typename It>
	void addNumbers(It first, It last);

	class TooLittleElementsException : public std::exception
	{
		const char* what(void) const throw();
	};

	class TooManyElementsException : public std::exception
	{
		const char* what(void) const throw();
	};
};

#include "Span.tpp"

#endif
