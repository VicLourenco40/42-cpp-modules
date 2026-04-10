#include "RPN.hpp"

#include <stack>
#include <stdexcept>

RPN::RPN(void) {}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN::~RPN(void) {}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

float RPN::calculate(const std::string& expr)
{
	static const std::invalid_argument invalidExpr("expr");

	std::stack<float> stack;
	float operand;

	for (std::string::const_iterator it = expr.begin(); it != expr.end(); ++it) {
		if (std::isspace(*it))
			continue;

		if (std::isdigit(*it)) {
			stack.push(*it - '0');
			continue;
		}

		if (stack.size() < 2)
			throw invalidExpr;

		operand = stack.top();
		stack.pop();

		switch (*it) {
			case '+':
				stack.top() += operand;
				break;
			case '-':
				stack.top() -= operand;
				break;
			case '*':
				stack.top() *= operand;
				break;
			case '/':
				if (operand == 0)
					throw invalidExpr;
				stack.top() /= operand;
				break;
			default:
				throw invalidExpr;
		}
	}

	if (stack.size() != 1)
		throw invalidExpr;

	return stack.top();
}
