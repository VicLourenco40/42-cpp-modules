#ifndef MATERIA_SOURCE
#define MATERIA_SOURCE

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const unsigned int max_materias = 4;
	AMateria* materias[max_materias];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	~MateriaSource(void);
	MateriaSource& operator=(const MateriaSource& other);
	void learnMateria(AMateria* materia);
	AMateria* createMateria(const std::string& type) const;
};

#endif
