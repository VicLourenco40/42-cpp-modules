#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	static const int fractBits = 8;
	int value;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	int getRawBits() const;
	void setRawBits(const int raw);
};

#endif
