#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	std::string name;

public:
	~Zombie();
	void announce() const;
	void setName(std::string name);
};

Zombie* zombieHorde(int n, std::string name);

#endif
