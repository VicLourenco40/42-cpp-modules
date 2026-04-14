#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <map>
#include <fstream>

#include <ctime>

class BitcoinExchange
{
private:
	typedef std::pair<std::time_t, float> entry_t;

	static std::map<std::time_t, float> db;

	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& other);

	BitcoinExchange& operator=(const BitcoinExchange& other);

	static entry_t parseCsvLine(const std::string& line, const char delim);

public:
	~BitcoinExchange(void);

	static void initializeDatabase(std::ifstream& dbFile);
	static void printRealValues(std::ifstream& inputFile);
};

#endif
