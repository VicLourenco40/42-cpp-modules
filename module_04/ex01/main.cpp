#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const unsigned int num_animals = 4;
	Animal* animals[num_animals];
	for (unsigned int i = 0; i < num_animals; ++i)
	{
		if (i < num_animals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << '\n';
	for (unsigned int i = 0; i < num_animals; ++i)
	{
		std::cout << animals[i]->getType() << " ";
		animals[i]->makeSound();
	}

	std::cout << '\n';
	for (unsigned int i = 0; i < num_animals; ++i)
		delete animals[i];

	std::cout << '\n';
	Dog dog;
	{
		std::cout << '\n';
		Dog temp;
		temp = dog;
		Dog temp2 = dog;
		std::cout << '\n';
	}
	std::cout << '\n';
}
