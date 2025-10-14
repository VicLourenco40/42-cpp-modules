#include <iostream>

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my\n";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
	std::cout << "I really do!\n\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years, whereas you started\n";
	std::cout << "working here just last month.\n\n";
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable!\n";
	std::cout << "I want to speak to the manager now.\n\n";
}

void Harl::complain(const std::string& str)
{
	static const std::string strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static const Level levels[4] = {DEBUG, INFO, WARNING, ERROR};

	Level level = INVALID;
	for (int i = 0; i < 4; i++) {
		if (str == strs[i])
			level = levels[i];
	}

	switch (level) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n\n";
	}
}
