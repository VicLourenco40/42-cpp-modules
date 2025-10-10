#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* str_ptr = &str;
	std::string& str_ref = str;

	std::cout << std::setw(29) << "str address: " << &str << '\n';
	std::cout << std::setw(29) << "address held by str_ptr: " << str_ptr << '\n';
	std::cout << std::setw(29) << "address held by str_ref: " << &str_ref << "\n\n";

	std::cout << std::setw(29) << "str value: " << str << '\n';
	std::cout << std::setw(29) << "value pointed to by str_ptr: " << *str_ptr << '\n';
	std::cout << std::setw(29) << "value pointed to by str_ref: " << str_ref << '\n';
}
