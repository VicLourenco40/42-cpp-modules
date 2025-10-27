#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	static const unsigned int max_materias = 4;
	std::string name;
	AMateria* materias[max_materias];

	Character(void);

public:
	Character(const std::string& name);
	Character(const Character& other);
	~Character(void);
	Character& operator=(const Character& other);
	const std::string& getName(void) const;
	void equip(AMateria* materia);
	void unequip(unsigned int id);
	void use(unsigned int id, const ICharacter& target) const;
};

#endif
