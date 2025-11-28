#include "Bureaucrat.hpp"

#include <iostream>

int main(void)
{
	Bureaucrat a("a", 150);
	std::cout << a << '\n';
	std::cout << '\n';

	Bureaucrat b("b", 1);
	std::cout << b << '\n';
	std::cout << '\n';

	try
	{
		Bureaucrat c("c", 151);
		std::cout << c << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "c constructor failed: " << e.what() << '\n';
	}
	std::cout << '\n';

	try
	{
		Bureaucrat d("d", 0);
		std::cout << d << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "d constructor failed: " << e.what() << '\n';
	}
	std::cout << '\n';

	try
	{
		Bureaucrat e("e", 149);
		std::cout << e << '\n';
		e.decrementGrade();
		std::cout << e << '\n';
		e.decrementGrade();
		std::cout << e << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "e grade decrement failed: " << e.what() << '\n';
	}
	std::cout << '\n';

	try
	{
		Bureaucrat f("f", 2);
		std::cout << f << '\n';
		f.incrementGrade();
		std::cout << f << '\n';
		f.incrementGrade();
		std::cout << f << '\n';
	}
	catch (const std::exception& f)
	{
		std::cout << "f grade increment failed: " << f.what() << '\n';
	}
}
