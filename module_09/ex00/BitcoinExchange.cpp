#include "BitcoinExchange.hpp"

#include <iostream>

#include <cstdlib>
#include <cerrno>

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(std::ifstream& dbFile)
{
	std::string line;
	std::getline(dbFile, line); // skip header

	entry_t entry;

	while (true)
	{
		std::getline(dbFile, line);
		if (dbFile.eof())
			break;

		entry = parseCsvLine(line, ',');
		if (entry.first == -1)
			continue;

		db.insert(entry);
		//std::cout << entry.first << ' ' << db[entry.first] << '\n';
	}
}

BitcoinExchange::~BitcoinExchange(void) {};

BitcoinExchange::entry_t BitcoinExchange::parseCsvLine(
	const std::string& line, const char delim) const
{
	static const std::string format = "%F%n";

	entry_t data;

	std::tm date = {};
	char *end = strptime(line.c_str(), (format + delim).c_str(), &date);
	data.first = std::mktime(&date);
	if (!end || *end == '\0' || data.first == -1)
		goto badInput;

	errno = 0;
	data.second = std::strtof(end, &end);
	if (*end != '\0' || errno == ERANGE)
		goto badInput;

	return data;

badInput:
	std::cerr << "error: bad input => " << line << '\n';
	return entry_t(-1, 0);
}

void BitcoinExchange::printRealValues(std::ifstream& inputFile) const
{
	const std::time_t earliestTime = db.begin()->first;

	std::string line;
	std::getline(inputFile, line); // skip header

	entry_t entry;
	float exchangeRate;
	char dateStr[11] = {};

	while (true)
	{
		std::getline(inputFile, line);
		if (inputFile.eof())
			break;

		entry = parseCsvLine(line, '|');
		if (entry.first == -1)
			continue;

		if (entry.first < earliestTime)
		{
			std::cerr << "error: date too early\n";
			continue;
		}
		if (entry.second < 0)
		{
			std::cerr << "error: negative value\n";
			continue;
		}
		if (entry.second > 1000)
		{
			std::cerr << "error: value too high\n";
			continue;
		}

		if (db.find(entry.first) == db.end())
			exchangeRate = (--db.lower_bound(entry.first))->second;
		else
			exchangeRate = db.at(entry.first);

		std::strftime(dateStr, 11, "%F", std::gmtime(&entry.first));
		std::cout << dateStr << " => " << entry.second
			<< " = " << exchangeRate * entry.second << '\n';
	}
}
