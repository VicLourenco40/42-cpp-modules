#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
private:
	AMateria(void);

protected:
	std::string type;

public:
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	virtual ~AMateria(void);
	AMateria& operator=(const AMateria& other);
	const std::string& getType(void) const;
	virtual AMateria* clone(void) const = 0;
	virtual void use(const ICharacter& target) const = 0;
};

#endif
