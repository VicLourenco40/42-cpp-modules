#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 4) {
		std::cout << "usage: sed <infile> <string> <replacement>\n";
		return 0;
	}

	std::ifstream in(argv[1]);
	if (!in.is_open()) {
		std::cerr << "failed to open file " << argv[1] << '\n';
		return 1;
	}

	const std::string out_name = std::string(argv[1]) + ".replace";
	std::ofstream out(out_name.c_str());
	if (!out.is_open()) {
		std::cerr << "failed to open file " << out_name << '\n';
		return 1;
	}

	const std::string str = argv[2];
	const std::string rep = argv[3];
	std::string line;
	std::string::size_type pos;

	while (true) {
		std::getline(in, line);
		pos = 0;
		while (true) {
			pos = line.find(str, pos);
			if (pos == std::string::npos)
				break;
			line.erase(pos, str.size());
			line.insert(pos, rep);
			pos += rep.size();
		}
		out << line;
		if (in.eof())
			break;
		out << '\n';
	}
}
