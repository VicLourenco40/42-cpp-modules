#ifndef RPN_H
#define RPN_H

#include <string>

class RPN
{
private:
	RPN(void);
	RPN(const RPN& other);

	RPN& operator=(const RPN& other);

public:
	~RPN(void);

	static float calculate(const std::string& expr);
};

#endif
