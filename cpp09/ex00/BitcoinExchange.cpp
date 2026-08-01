#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &dbFile)
{
	loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string &dbFile)
{
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	// Skip header line
	if (!std::getline(file, line))
		throw std::runtime_error("Error: database file is empty.");

	while (std::getline(file, line))
	{
		std::string::size_type commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		char *endPtr;
		double rate = std::strtod(rateStr.c_str(), &endPtr);
		if (*endPtr != '\0' && *endPtr != '\r')
			continue;

		_database[date] = rate;
	}
	file.close();

	if (_database.empty())
		throw std::runtime_error("Error: database is empty or invalid.");
}

bool BitcoinExchange::_isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::_isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (_isLeapYear(year))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

double BitcoinExchange::_getExchangeRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return it->second;

	if (it == _database.begin())
		return -1;

	--it;
	return it->second;
}

static std::string trimWhitespace(const std::string &str)
{
	std::string::size_type start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	std::string::size_type end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

void BitcoinExchange::processInputFile(const std::string &inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	// Skip header line
	if (std::getline(file, line))
	{
		std::string trimmed = trimWhitespace(line);
		// If it doesn't look like a header, process it as data
		if (trimmed != "date | value" && trimmed != "date|value")
		{
			// Not a header, rewind and process from the start
			file.clear();
			file.seekg(0, std::ios::beg);
		}
	}

	while (std::getline(file, line))
	{
		std::string trimmedLine = trimWhitespace(line);
		if (trimmedLine.empty())
			continue;

		// Find the pipe separator
		std::string::size_type pipePos = trimmedLine.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << trimmedLine << std::endl;
			continue;
		}

		std::string date = trimWhitespace(trimmedLine.substr(0, pipePos));
		std::string valueStr = trimWhitespace(trimmedLine.substr(pipePos + 1));

		// Validate date
		if (!_isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		// Validate value
		if (valueStr.empty())
		{
			std::cerr << "Error: bad input => " << trimmedLine << std::endl;
			continue;
		}

		char *endPtr;
		double value = std::strtod(valueStr.c_str(), &endPtr);
		if (*endPtr != '\0')
		{
			std::cerr << "Error: bad input => " << trimmedLine << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number => "<< trimmedLine << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number => " << trimmedLine << std::endl;
			continue;
		}

		// Get exchange rate
		double rate = _getExchangeRate(date);
		if (rate < 0)
		{
			std::cerr << "Error: date is before the database range." << std::endl;
			continue;
		}

		double result = value * rate;
		std::cout << date << " => " << valueStr << " = " << result << std::endl;
	}
	file.close();
}
