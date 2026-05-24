#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum LiteralType
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_SPECIAL_FLOAT,
	TYPE_SPECIAL_DOUBLE,
	TYPE_INVALID
};

enum PrintType
{
	PRINT_NORMAL,
	PRINT_NAN,
	PRINT_POS_INF,
	PRINT_NEG_INF,
	PRINT_DECIMAL
};

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &);
    ScalarConverter &operator=(ScalarConverter const &);
    ~ScalarConverter();

  public:
    static void convert(std::string const &literal);
};

#endif