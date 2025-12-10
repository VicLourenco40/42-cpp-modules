#include "Base.hpp"

#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	Base* ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;
}
