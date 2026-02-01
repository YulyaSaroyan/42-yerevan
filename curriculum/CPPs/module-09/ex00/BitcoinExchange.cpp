#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		this->_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &d) const
{
	if (d.size() != 10)
		return false;
	if (d[4] != '-' || d[7] != '-')
		return false;

	int y = std::atoi(d.substr(0, 4).c_str());
	int m = std::atoi(d.substr(5, 2).c_str());
	int day = std::atoi(d.substr(8, 2).c_str());

	if (m < 1 || m > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (y < 2009 || y > 2026)
		return false;

	return true;
}

bool BitcoinExchange::isValidNumber(const std::string &s) const
{
	if (s.empty())
		return false;

	bool dot = false;
	size_t start = 0;

	if (s[0] == '-' || s[0] == '+')
		start = 1;

	if (start >= s.size())
		return false;

	for (size_t i = start; i < s.size(); i++) {
		if (s[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!isdigit(s[i]))
			return false;
	}
	return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		if (line.empty())
			continue;

		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);
		double rate = atof(line.substr(comma + 1).c_str());

		_db[date] = rate;
	}

	file.close();
}

double BitcoinExchange::getClosestRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

	if (it != _db.end() && it->first == date)
		return it->second;

	if (it == _db.begin())
		return -1;

	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		if (line.empty())
			continue;

		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipe - 1);
		std::string value = line.substr(pipe + 2);

		while (date.size() && date[0] == ' ') date.erase(0, 1);
		while (value.size() && value[0] == ' ') value.erase(0, 1);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidNumber(value)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double num = atof(value.c_str());

		if (num < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (num > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = getClosestRate(date);
		if (rate < 0) {
			std::cerr << "Error: date too early." << std::endl;
			continue;
		}

		double result = num * rate;
		std::cout << date << " => " << num << " = " << result << std::endl;
	}

	file.close();
}
