#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	enum scalarType
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		INVALID
	};

	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& other);

	static scalarType detectType(const std::string& str);

	static void printScalar(char c);
	static void printScalar(int i);
	static void printScalar(float f);
	static void printScalar(double d);
	static void printImpossible(scalarType type);

	static void convertScalar(char c);
	static void convertScalar(int i);
	static void convertScalar(float f);
	static void convertScalar(double d);

public:
	~ScalarConverter(void);

	ScalarConverter& operator=(const ScalarConverter& other);

	static void convert(const std::string& str);
};

#endif
