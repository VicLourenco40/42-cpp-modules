#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <map>
#include <fstream>

#include <ctime>

class BitcoinExchange
{
private:
	typedef std::pair<std::time_t, float> entry_t;

	std::map<std::time_t, float> db;

	BitcoinExchange(void);

	entry_t parseCsvLine(const std::string& line, const char delim) const;

public:
	BitcoinExchange(std::ifstream& dbFile);
	~BitcoinExchange(void);

	void printRealValues(std::ifstream& inputFile) const;
};

#endif
