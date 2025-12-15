#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>
#include <cstring>

template<typename T>
Array<T>::Array(void) : arr(NULL), n(0) {}

template<typename T>
Array<T>::Array(const Array& other) : arr(new T[other.n]()), n(other.n)
{
	std::memcpy(arr, other.arr, n);
}

template<typename T>
Array<T>::Array(const unsigned int n) : arr(new T[n]()), n(n) {}

template<typename T>
Array<T>::~Array(void)
{
	delete[] arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	n = other.n;
	delete[] arr;
	arr = new T[n]();
	std::memcpy(arr, other.arr, n);
}

template<typename T>
T& Array<T>::operator[](const unsigned int i) const
{
	if (i >= n)
		throw std::out_of_range("Array index out of range");
	return arr[i];
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return n;
}

#endif
