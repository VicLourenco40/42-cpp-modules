#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int num) : value(num << fractBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num) : value(roundf(num * (1 << fractBits)))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	value = other.value;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return value;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	value = raw;
}

int Fixed::toInt() const
{
	return value >> fractBits;
}

float Fixed::toFloat() const
{
	return value / static_cast<float>(1 << fractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	return os << obj.toFloat();
}
