#include "RPN.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "usage: RPN <expression>\n";
		return 1;
	}

	try {
		std::cout << RPN::calculate(argv[1]) << '\n';
	} catch (...) {
		std::cerr << "error\n";
	}
}
