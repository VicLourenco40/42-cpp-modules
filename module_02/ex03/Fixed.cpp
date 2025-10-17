#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	//std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

Fixed::Fixed(const int num) : value(num << fractBits)
{
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num) : value(roundf(num * (1 << fractBits)))
{
	//std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	//std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called\n";
	value = other.value;
	return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
	return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed ret = *this;
	ret.value += other.value;
	return ret;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed ret = *this;
	ret.value -= other.value;
	return ret;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	value++;
	return old;
}

Fixed& Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	value--;
	return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called\n";
	return value;
}

void Fixed::setRawBits(const int raw)
{
	//std::cout << "setRawBits member function called\n";
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
