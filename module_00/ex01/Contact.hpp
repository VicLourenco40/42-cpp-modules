#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	static void display_header();
	void display();
	void display(int index);
	void fill_fields();
};

#endif
