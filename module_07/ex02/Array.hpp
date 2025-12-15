#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
private:
	T* arr;
	unsigned int n;

public:
	Array(void);
	Array(const Array& other);
	Array(unsigned int n);
	~Array(void);

	Array& operator=(const Array& other);
	T& operator[](unsigned int i) const;

	unsigned int size(void) const;
};

#include "Array.tpp"

#endif
