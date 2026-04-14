#include "BitcoinExchange.hpp"

#include <iostream>

#include <cstdlib>
#include <cerrno>

std::map<std::time_t, float> BitcoinExchange::db;

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange::~BitcoinExchange(void) {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

BitcoinExchange::entry_t BitcoinExchange::parseCsvLine(
	const std::string& line, const char delim)
{
	static const std::string format = "%F%n";

	entry_t data;

	std::tm date = {};
	char *end = strptime(line.c_str(), (format + delim).c_str(), &date);
	data.first = std::mktime(&date);
	if (!end || *end == '\0' || data.first == -1)
		return entry_t(-1, 0);

	errno = 0;
	data.second = std::strtof(end, &end);
	if (*end != '\0' || errno == ERANGE)
		return entry_t(-1, 0);

	return data;
}

void BitcoinExchange::initializeDatabase(std::ifstream &dbFile)
{
	db.clear();

	std::string line;
	std::getline(dbFile, line); // skip header

	entry_t entry;

	while (true) {
		std::getline(dbFile, line);
		if (dbFile.eof())
			break;

		entry = parseCsvLine(line, ',');
		if (entry.first == -1)
			std::cerr << "error: bad db entry => " << line << '\n';
		else
			db.insert(entry);
	}
}

void BitcoinExchange::printRealValues(std::ifstream& inputFile)
{
	const std::time_t earliestTime = db.begin()->first;

	std::string line;
	std::getline(inputFile, line); // skip header

	entry_t entry;
	float exchangeRate;
	char dateStr[11] = {};

	while (true) {
		std::getline(inputFile, line);
		if (inputFile.eof())
			break;

		entry = parseCsvLine(line, '|');
		if (entry.first == -1)
			std::cerr << "error: bad input => " << line << '\n';
		else if (entry.first < earliestTime)
			std::cerr << "error: date too early\n";
		else if (entry.second < 0)
			std::cerr << "error: negative value\n";
		else if (entry.second > 1000)
			std::cerr << "error: value too high\n";
		else {
			if (db.find(entry.first) == db.end())
				exchangeRate = (--db.lower_bound(entry.first))->second;
			else
				exchangeRate = db.at(entry.first);

			std::strftime(dateStr, 11, "%F", std::gmtime(&entry.first));
			std::cout << dateStr << " => " << entry.second
				<< " = " << exchangeRate * entry.second << '\n';
		}
	}
}
