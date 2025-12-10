#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base::~Base(void) {}

Base* generate(void)
{
	switch(std::rand() % 3)
	{
		case 0:
			//std::cout << "instantiated A\n";
			return new A;
		case 1:
			//std::cout << "instantiated B\n";
			return new B;
		default:
			//std::cout << "instantiated C\n";
			return new C;
	}
}

void identify(const Base *const ptr)
{
	if (dynamic_cast<const A*>(ptr))
		std::cout << "A\n";
	else if (dynamic_cast<const B*>(ptr))
		std::cout << "B\n";
	else if (dynamic_cast<const C*>(ptr))
		std::cout << "C\n";
}

void identify(const Base& ref)
{
	try
	{
		(void)dynamic_cast<const A&>(ref);
		std::cout << "A\n";
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<const B&>(ref);
		std::cout << "B\n";
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<const C&>(ref);
		std::cout << "C\n";
	}
	catch (...) {}
}
