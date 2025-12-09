#include "ScalarConverter.hpp"

#include <iostream>
#include <ios>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cerrno>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::scalarType ScalarConverter::detectType(const std::string& str)
{
	if (str.size() == 0)
		return INVALID;

	if (str.size() == 1 && !std::isdigit(str[0]))
		return CHAR;

	char* end;

	long l;
	l = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0' && l >= INT_MIN && l <= INT_MAX)
		return INT;

	errno = 0;
	double d;
	d = std::strtod(str.c_str(), &end);
	if (*end == '\0' && errno != ERANGE)
		return DOUBLE;

	errno = 0;
	float f;
	f = std::strtof(str.c_str(), &end);
	if ((end[0] == 'f' || end[0] == 'F') && end[1] == '\0' && errno != ERANGE)
		return FLOAT;

	return INVALID;
}

void ScalarConverter::printScalar(const char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: non displayable\n";
}

void ScalarConverter::printScalar(const int i)
{
	std::cout << "int: " << i << '\n';
}

void ScalarConverter::printScalar(const float f)
{
	std::cout << "float: " << std::showpoint << f << "f\n";
}

void ScalarConverter::printScalar(const double d)
{
	std::cout << "double: " << std::showpoint << d << '\n';
}

void ScalarConverter::printImpossible(const scalarType type)
{
	switch (type)
	{
		case CHAR:
			std::cout << "char";
			break;
		case INT:
			std::cout << "int";
			break;
		case FLOAT:
			std::cout << "float";
			break;
		case DOUBLE:
			std::cout << "double";
			break;
		case INVALID:
			return ;
	}
	std::cout << ": impossible\n";
}

void ScalarConverter::convertScalar(const char c)
{
	printScalar(c);
	printScalar(static_cast<int>(c));
	printScalar(static_cast<float>(c));
	printScalar(static_cast<double>(c));
}

void ScalarConverter::convertScalar(const int i)
{
	if (i >= CHAR_MIN && i <= CHAR_MAX)
		printScalar(static_cast<char>(i));
	else
		printImpossible(CHAR);
	printScalar(i);
	if (i >= -FLT_MAX && i <= FLT_MAX)
		printScalar(static_cast<float>(i));
	else
		printImpossible(FLOAT);
	if (i >= -DBL_MAX && i <= DBL_MAX)
		printScalar(static_cast<double>(i));
	else
		printImpossible(DOUBLE);
}

void ScalarConverter::convertScalar(const float f)
{
	if (f >= CHAR_MIN && f <= CHAR_MAX)
		printScalar(static_cast<char>(f));
	else
		printImpossible(CHAR);
	if (f >= INT_MIN && static_cast<int>(f) <= INT_MAX)
		printScalar(static_cast<int>(f));
	else
		printImpossible(INT);
	printScalar(f);
	printScalar(static_cast<double>(f));
}

void ScalarConverter::convertScalar(const double d)
{
	if (d >= CHAR_MIN && d <= CHAR_MAX)
		printScalar(static_cast<char>(d));
	else
		printImpossible(CHAR);
	if (d >= INT_MIN && d <= INT_MAX)
		printScalar(static_cast<int>(d));
	else
		printImpossible(INT);
	if ((d >= -FLT_MAX && d <= FLT_MAX) || std::isinf(d) || std::isnan(d))
		printScalar(static_cast<float>(d));
	else
		printImpossible(FLOAT);
	printScalar(d);
}

void ScalarConverter::convert(const std::string& str)
{
	switch (detectType(str))
	{
		case CHAR:
			convertScalar(str[0]);
			break;
		case INT:
			convertScalar(static_cast<int>(std::strtol(str.c_str(), NULL, 10)));
			break;
		case FLOAT:
			convertScalar(std::strtof(str.c_str(), NULL));
			break;
		case DOUBLE:
			convertScalar(std::strtod(str.c_str(), NULL));
			break;
		case INVALID:
			printImpossible(CHAR);
			printImpossible(INT);
			printImpossible(FLOAT);
			printImpossible(DOUBLE);
	}
}
