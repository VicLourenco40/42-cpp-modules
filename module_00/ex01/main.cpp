#include <iostream>

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while (true)
	{
		std::cout << "[ADD/SEARCH/EXIT]: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << '\n';
			break;
		}
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			break;
	}
}
