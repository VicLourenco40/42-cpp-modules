#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	static const unsigned int num_ideas = 100;
	std::string ideas[num_ideas];

public:
	Brain(void);
	Brain(const Brain& other);
	~Brain(void);
	Brain& operator=(const Brain& other);
};

#endif
