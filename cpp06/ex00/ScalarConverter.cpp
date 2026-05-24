#include "ScalarConverter.hpp"

#include <cerrno>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

// Canonical Form
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

// Type Definition
static bool isSpecialFloat(const std::string& literal) {
	return literal == "nanf" || literal == "+inff" || literal == "-inff";
}

static bool isSpecialDouble(const std::string& literal) {
	return literal == "nan" || literal == "+inf" || literal == "-inf";
}

static bool isCharLiteral(const std::string& literal) {
	return (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])));
}


static bool isNan(double value) {
	return value != value;
}

static bool isInfinite(double value) {
	return (value == std::numeric_limits<double>::infinity()
	|| value == -std::numeric_limits<double>::infinity());
}

static bool isImpossibleInt(double value) {
	return isNan(value)
	|| isInfinite(value)
	|| value < static_cast<double>(std::numeric_limits<int>::min())
	|| value > static_cast<double>(std::numeric_limits<int>::max());
}

static bool isImpossibleChar(double value) {
	return isNan(value)
	|| isInfinite(value)
	|| value < static_cast<double>(std::numeric_limits<char>::min())
	|| value > static_cast<double>(std::numeric_limits<char>::max());
}

static bool hasDecimalPoint(const std::string& literal) {
	std::string::size_type i;

	i = 0;
	while (i < literal.length())
	{
		if (literal[i] == '.')
			return true;
		++i;
	}
	return false;
}

static bool needsDecimalSuffix(double value) {
	return !isNan(value) && !isInfinite(value) && std::floor(value) == value;
}

// Parsing
static bool parseLong(const std::string& literal, long& value) {
	char* end;
	
	errno = 0;
	value = std::strtol(literal.c_str(), &end, 10);
	return end != literal.c_str() && *end == '\0' && errno != ERANGE;
}

static bool parseDouble(const std::string& literal, double& value) {
	char* end;

	errno = 0;
	value = std::strtod(literal.c_str(), &end);
	return (end != literal.c_str() && *end == '\0' && errno != ERANGE);
}

// Validation
static bool isValidFloatLiteral(const std::string& literal) {
	std::string	withoutF;
	double		value;

	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return false;
	withoutF = literal.substr(0, literal.length() - 1);
	if (!hasDecimalPoint(withoutF))
		return false;
	return parseDouble(withoutF, value);
}

static bool isValidDoubleLiteral(const std::string& literal) {
	double value;

	if (!hasDecimalPoint(literal))
		return false;
	return parseDouble(literal, value);
}

static LiteralType detectType(const std::string& literal) {
	long intValue;

	if (isSpecialFloat(literal))
		return TYPE_SPECIAL_FLOAT;
	if (isSpecialDouble(literal))
		return TYPE_SPECIAL_DOUBLE;
	if (isCharLiteral(literal))
		return TYPE_CHAR;
	if (parseLong(literal, intValue) && intValue >= std::numeric_limits<int>::min()
		&& intValue <= std::numeric_limits<int>::max())
		return TYPE_INT;
	if (isValidFloatLiteral(literal))
		return TYPE_FLOAT;
	if (isValidDoubleLiteral(literal))
		return TYPE_DOUBLE;
	return TYPE_INVALID;
}

// Print
static PrintType getPrintType(double value) {
	if (isNan(value))
		return PRINT_NAN;
	if (value == std::numeric_limits<double>::infinity())
		return PRINT_POS_INF;
	if (value == -std::numeric_limits<double>::infinity())
		return PRINT_NEG_INF;
	if (needsDecimalSuffix(value))
		return PRINT_DECIMAL;
	return PRINT_NORMAL;
}

static void printChar(double value) {
	char c;

	std::cout << "char: ";
	if (isImpossibleChar(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}
	std::cout << "'" << c << "'" << std::endl;
}

static void printInt(double value) {
	std::cout << "int: ";
	if (isImpossibleInt(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
	float			f;
	std::ostringstream	stream;

	f = static_cast<float>(value);
	std::cout << "float: ";
	switch (getPrintType(static_cast<double>(f)))
	{
		case PRINT_NAN:
			std::cout << "nan";
			break;
		case PRINT_POS_INF:
			std::cout << "+inf";
			break;
		case PRINT_NEG_INF:
			std::cout << "-inf";
			break;
		case PRINT_DECIMAL:
			stream << std::fixed << std::setprecision(1) << f;
			std::cout << stream.str();
			break;
		case PRINT_NORMAL:
			std::cout << f;
			break;
	}
	std::cout << "f" << std::endl;
}

static void printDouble(double value) {
	std::ostringstream stream;

	std::cout << "double: ";
	switch (getPrintType(value))
	{
		case PRINT_NAN:
			std::cout << "nan";
			break;
		case PRINT_POS_INF:
			std::cout << "+inf";
			break;
		case PRINT_NEG_INF:
			std::cout << "-inf";
			break;
		case PRINT_DECIMAL:
			stream << std::fixed << std::setprecision(1) << value;
			std::cout << stream.str();
			break;
		case PRINT_NORMAL:
			std::cout << value;
			break;
	}
	std::cout << std::endl;
}

static void printAll(double value) {
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

// Define Value
static bool valueFromLiteral(const std::string& literal, LiteralType type, double& value) {
	long		intValue;
	std::string	withoutF;

	switch (type)
	{
		case TYPE_CHAR:
			value = static_cast<double>(literal[0]);
			return true;
		case TYPE_INT:
			if (!parseLong(literal, intValue))
				return false;
			value = static_cast<double>(static_cast<int>(intValue));
			return true;
		case TYPE_FLOAT:
			withoutF = literal.substr(0, literal.length() - 1);
			return parseDouble(withoutF, value);
		case TYPE_DOUBLE:
			return parseDouble(literal, value);
		case TYPE_SPECIAL_FLOAT:
			withoutF = literal.substr(0, literal.length() - 1);
			return parseDouble(withoutF, value);
		case TYPE_SPECIAL_DOUBLE:
			return parseDouble(literal, value);
		case TYPE_INVALID:
			return false;
	}
	return false;
}

// Main Function
void ScalarConverter::convert(const std::string& literal) {
	LiteralType	type;
	double		value;

	type = detectType(literal);
	switch (type)
	{
		case TYPE_CHAR:
		case TYPE_INT:
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
		case TYPE_SPECIAL_FLOAT:
		case TYPE_SPECIAL_DOUBLE:
			if (valueFromLiteral(literal, type, value))
				printAll(value);
			else
				printAll(std::numeric_limits<double>::quiet_NaN());
			break;
		case TYPE_INVALID:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}