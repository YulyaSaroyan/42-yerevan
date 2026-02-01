#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double> _db;

	bool isValidDate(const std::string &date) const;
	bool isValidNumber(const std::string &s) const;
	double getClosestRate(const std::string &date) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadDatabase(const std::string &filename);
	void processInput(const std::string &filename);
};

#endif
