#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <climits>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _rates;

		static bool   isValidDate(const std::string &date);
		static bool   isLeapYear(int year);
		static int    toInt(const std::string &str);
		static double parsePositiveValue(const std::string &value);
		static double parseRate(const std::string &rate);
		static std::string trim(const std::string &str);

		double getRateForDate(const std::string &date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename) const;
};

#endif