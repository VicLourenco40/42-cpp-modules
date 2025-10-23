#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* animal = new Animal();
	std::cout << animal->getType() << ' ';
	animal->makeSound();
	delete animal;
	std::cout << '\n';

	const Animal* dog = new Dog();
	std::cout << dog->getType() << ' ';
	dog->makeSound();
	delete dog;
	std::cout << '\n';

	const Animal* cat = new Cat();
	std::cout << cat->getType() << ' ';
	cat->makeSound();
	delete cat;
	std::cout << '\n';

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << wrongAnimal->getType() << ' ';
	wrongAnimal->makeSound();
	delete wrongAnimal;
	std::cout << '\n';

	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << ' ';
	wrongCat->makeSound();
	delete wrongCat;
	std::cout << '\n';

	const WrongCat* wrongCat2 = new WrongCat();
	std::cout << wrongCat2->getType() << ' ';
	wrongCat2->makeSound();
	delete wrongCat2;
}
