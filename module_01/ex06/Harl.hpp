#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	void debug();
	void info();
	void warning();
	void error();

public:
	enum Level {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		INVALID
	};

	void complain(const std::string& str);
};

#endif
