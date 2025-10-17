#include <iostream>
#include "Fixed.hpp"

int main()
{
	Fixed a;
	const Fixed b(Fixed(5.05f) * Fixed(2));

	std::cout << a << '\n';
	std::cout << ++a << '\n';
	std::cout << a << '\n';
	std::cout << a++ << '\n';
	std::cout << a << '\n';

	std::cout << b << '\n';

	std::cout << Fixed::max(a, b) << '\n';
}

/*
int main()
{
	std::cout << (Fixed(1) > Fixed(2)) << '\n';
	std::cout << (Fixed(2) > Fixed(1)) << '\n';
	std::cout << '\n';

	std::cout << (Fixed(1) < Fixed(2)) << '\n';
	std::cout << (Fixed(2) < Fixed(1)) << '\n';
	std::cout << '\n';

	std::cout << (Fixed(1) >= Fixed(2)) << '\n';
	std::cout << (Fixed(2) >= Fixed(1)) << '\n';
	std::cout << (Fixed(1) >= Fixed(1)) << '\n';
	std::cout << '\n';

	std::cout << (Fixed(1) <= Fixed(2)) << '\n';
	std::cout << (Fixed(2) <= Fixed(1)) << '\n';
	std::cout << (Fixed(1) <= Fixed(1)) << '\n';
	std::cout << '\n';

	std::cout << (Fixed(1) == Fixed(1)) << '\n';
	std::cout << (Fixed(1) == Fixed(2)) << '\n';
	std::cout << '\n';

	std::cout << (Fixed(1) != Fixed(1)) << '\n';
	std::cout << (Fixed(1) != Fixed(2)) << '\n';
	std::cout << '\n';

	std::cout << (Fixed(1) + Fixed(0.5f)) << '\n';
	std::cout << (Fixed(1) - Fixed(0.5f)) << '\n';
	std::cout << (Fixed(1) * Fixed(0.5f)) << '\n';
	std::cout << (Fixed(1) / Fixed(0.5f)) << '\n';
	std::cout << '\n';

	Fixed a(1);
	std::cout << ++a << ' ' << a << '\n';
	a = 1;
	std::cout << a++ << ' ' << a << '\n';
	std::cout << '\n';

	a = 1;
	std::cout << --a << ' ' << a << '\n';
	a = 1;
	std::cout << a-- << ' ' << a << '\n';
	std::cout << '\n';

	const Fixed b(1);
	const Fixed c(2);
	std::cout << Fixed::min(Fixed(1), Fixed(2)) << '\n';
	std::cout << Fixed::min(b, c) << '\n';
	std::cout << '\n';

	std::cout << Fixed::max(Fixed(1), Fixed(2)) << '\n';
	std::cout << Fixed::max(b, c) << '\n';
}
*/
