#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal& other);
	virtual ~Animal(void);
	Animal& operator=(const Animal& other);
	const std::string& getType(void) const;
	virtual void makeSound(void) const = 0;
};

#endif
