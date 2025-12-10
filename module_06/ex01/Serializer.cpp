#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer::~Serializer(void) {}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(const Data *const ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(const uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
