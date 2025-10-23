#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	//Animal animal;

	Animal* dog = new Dog();
	std::cout << dog->getType() << ' ';
	dog->makeSound();
	delete dog;

	std::cout << '\n';
	Animal* cat = new Cat();
	std::cout << cat->getType() << ' ';
	cat->makeSound();
	delete cat;
}
