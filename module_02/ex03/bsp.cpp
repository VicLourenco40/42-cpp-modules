#include "Point.hpp"

Fixed triangleArea(const Point& a, const Point& b, const Point& c)
{
	Fixed area((
		a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY() -
		b.getX() * a.getY() + c.getX() * b.getY() + a.getX() * c.getY()) *
		0.5f);
	return area >= 0 ? area : area * -1;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed abcArea = triangleArea(a, b, c);
	Fixed abpArea = triangleArea(a, b, point);
	Fixed acpArea = triangleArea(a, c, point);
	Fixed bcpArea = triangleArea(b, c, point);

	if (!abpArea.getRawBits() || !acpArea.getRawBits() || !bcpArea.getRawBits())
		return false;
	if (abcArea == abpArea + acpArea + bcpArea)
		return true;
	return false;
}
