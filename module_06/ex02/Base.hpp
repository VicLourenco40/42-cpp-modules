#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
	virtual ~Base(void);
};

Base* generate(void);
void identify(const Base* ptr);
void identify(const Base& ref);

#endif
