#include <iostream>
#include <cctype>

static void print_capitalized(const std::string& str)
{
	std::string::const_iterator it;

	for(it = str.begin(); it != str.end(); ++it)
		std::cout << static_cast<char>(std::toupper(*it));
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	while (*++argv)
		print_capitalized(std::string(*argv));
	std::cout << '\n';
}
