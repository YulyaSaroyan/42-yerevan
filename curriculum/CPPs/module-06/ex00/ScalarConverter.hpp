#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include "print.hpp"

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();

	static bool isChar(const std::string&);
	static bool isInt(const std::string&);
	static bool isFloat(const std::string&);
	static bool isDouble(const std::string&);
	static bool isFloatPseudo(const std::string&);
	static bool isDoublePseudo(const std::string&);
public:
	static void convert(const std::string &);
};

#endif
