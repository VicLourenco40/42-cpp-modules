#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

#include <stdint.h>

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer& other);

public:
	~Serializer(void);

	Serializer& operator=(const Serializer& other);

	static uintptr_t serialize(const Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
