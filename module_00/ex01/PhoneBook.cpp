#include <iostream>
#include <cstdlib>

#include "PhoneBook.hpp"

const int PhoneBook::max_contacts;

PhoneBook::PhoneBook() : num_contacts(0) {};

void PhoneBook::add_contact()
{
	if (num_contacts >= max_contacts)
	{
		for (int i = 0; i + 1 < max_contacts; i++)
			contacts[i] = contacts[i + 1];
	}
	else {
		num_contacts++;
	}
	contacts[num_contacts - 1].fill_fields();
}

void PhoneBook::search_contact() const
{
	if (num_contacts == 0) {
		std::cout << "\nNo contacts.\n\n";
		return;
	}

	std::cout << '\n';
	Contact::display_header();
	for (int i = 0; i < num_contacts; i++)
		contacts[i].display(i + 1);
	std::cout << '\n';

	std::string input;
	int index;
	do {
		std::cout << "Index: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << '\n';
			std::exit(1);
		}
		index = std::atoi(input.c_str()) - 1;
	} while (index < 0 || index >= num_contacts);

	std::cout << '\n';
	contacts[index].display();
	std::cout << '\n';
}
