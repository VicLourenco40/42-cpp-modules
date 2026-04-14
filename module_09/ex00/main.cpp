#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "usage: btc <input file>\n";
		return 1;
	}

	std::ifstream dbFile("./data.csv");
	if (!dbFile.is_open()) {
		std::cerr << "error: unable to open data.csv\n";
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "error: unable to open " << argv[1] << '\n';
		return 1;
	}

	BitcoinExchange::initializeDatabase(dbFile);
	dbFile.close();

	BitcoinExchange::printRealValues(inputFile);
	inputFile.close();
}
