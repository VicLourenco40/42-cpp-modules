#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	static const int max_contacts = 8;
	Contact contacts[max_contacts];
	int num_contacts;

public:
	PhoneBook();
	void add_contact();
	void search_contact() const;
};

#endif
