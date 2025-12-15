#include "Array.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 750

int main(void)
{
	srand(time(NULL));

	Array<int> numbers(MAX_VAL);
	int *const mirror = new int[MAX_VAL];

	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "numbers and mirror values differ" << '\n';
			delete[] mirror;
			return 1;
		}
	}

	delete[] mirror;

	try
	{
		numbers[-1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	{
		Array<int> empty;
		Array<int> tmp = numbers;
		Array<int> test(numbers);
	}

	{
		Array<std::string> strings(2);
		strings[0] = "abcd";
		strings[1] = "efgh";
		std::cout << strings.size() << ' '
				  << strings[0] << ' '
				  << strings[1] << '\n';
	}
}
