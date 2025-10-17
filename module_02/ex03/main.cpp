#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main()
{
	Point a(0, 0);
	Point b(0, 2);
	Point c(2, 0);

	std::cout << bsp(a, b, c, Point(0.5f, 0.5f)) << '\n';
	std::cout << bsp(a, b, c, Point(0, 0)) << '\n';
	std::cout << bsp(a, b, c, Point(0, 2)) << '\n';
	std::cout << bsp(a, b, c, Point(2, 0)) << '\n';
	std::cout << bsp(a, b, c, Point(2, 2)) << '\n';
	std::cout << bsp(a, b, c, Point(1, 1)) << '\n';
}
