#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	static const int fractBits = 8;
	int value;

public:
	Fixed();
	~Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	int getRawBits() const;
	void setRawBits(const int raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
