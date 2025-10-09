#include <iostream>
#include <cctype>

static void capitalize_string(char* string)
{
	while (*string) {
		*string = toupper(*string);
		string++;
	}
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	argv++;
	while (*argv) {
		capitalize_string(*argv);
		std::cout << *argv;
		argv++;
	}
	std::cout << '\n';
}
