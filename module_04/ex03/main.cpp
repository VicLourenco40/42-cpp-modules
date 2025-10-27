#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	std::cout << '\n';
	ICharacter* bob = new Character("bob");
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = source->createMateria("ice");
	me->equip(tmp);
	tmp = source->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);
	me->equip(tmp);
	delete me;
	delete bob;

	std::cout << '\n';
	Character dummy("dummy");
	Character orig("character");
	tmp = source->createMateria("ice");
	orig.equip(tmp);
	tmp = source->createMateria("cure");
	orig.equip(tmp);
	orig.use(0, dummy);
	orig.use(1, dummy);
	{
		std::cout << '\n';
		Character copy = orig;
		orig.use(0, dummy);
		orig.use(1, dummy);
	}

	std::cout << '\n';
	delete source;
	std::cout << '\n';
}
