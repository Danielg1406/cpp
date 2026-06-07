#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &str)
{
	std::size_t start = 0;
	std::size_t end = str.size();

	while (start < str.size() && (str[start] == ' ' || str[start] == '\t'))
		++start;

	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		--end;

	return str.substr(start, end - start);
}

int BitcoinExchange::toInt(const std::string &str)
{
	std::istringstream iss(str);
	int value;

	iss >> value;
	if (iss.fail())
		return -1;
	return value;
}

bool BitcoinExchange::isLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return year % 4 == 0;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (std::size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year = toInt(date.substr(0, 4));
	int month = toInt(date.substr(5, 2));
	int day = toInt(date.substr(8, 2));

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	return day <= daysInMonth[month - 1];
}

double BitcoinExchange::parsePositiveValue(const std::string &value)
{
	char *end;
	double result;

	errno = 0;
	result = std::strtod(value.c_str(), &end);

	if (end == value.c_str() || *end != '\0' || errno == ERANGE)
		throw std::runtime_error("Error: bad input => " + value);

	if (result < 0)
		throw std::runtime_error("Error: not a positive number.");

	if (result > 1000)
		throw std::runtime_error("Error: too large a number.");

	return result;
}

double BitcoinExchange::parseRate(const std::string &rate)
{
	char *end;
	double result;

	errno = 0;
	result = std::strtod(rate.c_str(), &end);

	if (end == rate.c_str() || *end != '\0' || errno == ERANGE)
		throw std::runtime_error("Error: invalid database.");

	if (result < 0)
		throw std::runtime_error("Error: invalid database.");

	return result;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::size_t comma = line.find(',');

		if (comma == std::string::npos)
			throw std::runtime_error("Error: invalid database.");

		std::string date = trim(line.substr(0, comma));
		std::string rate = trim(line.substr(comma + 1));

		if (!isValidDate(date))
			throw std::runtime_error("Error: invalid database.");

		_rates[date] = parseRate(rate);
	}

	if (_rates.empty())
		throw std::runtime_error("Error: invalid database.");
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

	if (it != _rates.end() && it->first == date)
		return it->second;

	if (it == _rates.begin())
		throw std::runtime_error("Error: bad input => " + date);

	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		try
		{
			std::size_t sep = line.find('|');

			if (sep == std::string::npos)
				throw std::runtime_error("Error: bad input => " + line);

			std::string date = trim(line.substr(0, sep));
			std::string valueStr = trim(line.substr(sep + 1));

			if (!isValidDate(date))
				throw std::runtime_error("Error: bad input => " + line);

			double value = parsePositiveValue(valueStr);
			double rate = getRateForDate(date);

			std::cout << date << " => " << valueStr << " = "
					  << value * rate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}