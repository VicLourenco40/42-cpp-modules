#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal& animal = Animal();
	std::cout << animal.getType() << '\n';
	animal.makeSound();
	std::cout << '\n';

	const Animal& dog = Dog();
	std::cout << dog.getType() << '\n';
	dog.makeSound();
	std::cout << '\n';

	const Animal& cat = Cat();
	std::cout << cat.getType() << '\n';
	cat.makeSound();
	std::cout << '\n';

	const WrongAnimal& wrongAnimal = WrongAnimal();
	std::cout << wrongAnimal.getType() << '\n';
	wrongAnimal.makeSound();
	std::cout << '\n';

	const WrongAnimal& wrongCat = WrongCat();
	std::cout << wrongCat.getType() << '\n';
	wrongCat.makeSound();
	std::cout << '\n';

	const WrongCat& wrongCat2 = WrongCat();
	std::cout << wrongCat2.getType() << '\n';
	wrongCat2.makeSound();
	std::cout << '\n';
}
