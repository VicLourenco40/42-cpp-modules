#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Contact.hpp"

static bool is_str_whitespace(const char *str)
{
	while (*str)
	{
		if (!isspace(*str))
			return (false);
		str++;
	}
	return (true);
}

static void get_input(const std::string prompt, std::string& str)
{
	do {
		std::cout << prompt;
		std::getline(std::cin, str);
		if (std::cin.eof()){
			std::cout << '\n';
			std::exit(1);
		}
	} while (str.empty() || is_str_whitespace(str.c_str()));
}

void Contact::fill_fields()
{
	get_input("First name: ", first_name);
	get_input("Last name: ", last_name);
	get_input("Nickname: ", nickname);
	get_input("Phone number: ", phone_number);
	get_input("Darkest secret: ", darkest_secret);
	std::cout << "\nContact " << first_name << ' ' << last_name << " added.\n\n";
}

void Contact::display() const
{
	std::cout << std::setw(17) << "First name | " << first_name << '\n';
	std::cout << std::setw(17) << "Last name | " << last_name << '\n';
	std::cout << std::setw(17) << "Nickname | " << nickname << '\n';
	std::cout << std::setw(17) << "Phone number | " << phone_number << '\n';
	std::cout << std::setw(17) << "Darkest secret | " << darkest_secret << '\n';
}

static std::string truncate_field(const std::string& field)
{
	if (field.size() > 10)
		return field.substr(0, 9) + '.';
	return field;
}

void Contact::display(int index) const
{
	std::cout << std::setw(10) << index << '|';
	std::cout << std::setw(10) << truncate_field(first_name) << '|';
	std::cout << std::setw(10) << truncate_field(last_name) << '|';
	std::cout << std::setw(10) << truncate_field(nickname) << '\n';
}

void Contact::display_header()
{
	std::cout << std::setw(10) << "Index" << '|';
	std::cout << std::setw(10) << "First Name" << '|';
	std::cout << std::setw(10) << "Last Name" <<  '|';
	std::cout << std::setw(10) << "Nickname" << '\n';
}
