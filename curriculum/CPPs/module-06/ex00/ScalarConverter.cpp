#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
	return (str.size() == 1 && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string& str) {
	if (str.empty()) return false;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+') i++;
	if (i >= str.size()) return false;
	for (; i < str.size(); i++)
		if (!std::isdigit(str[i])) return false;
	return true;
}

bool ScalarConverter::isFloatPseudo(const std::string& str) {
   return (str == "+inff" || str == "inff"|| str == "-inff" || str == "nanf");
}

bool ScalarConverter::isDoublePseudo(const std::string& str) {
	return (str == "+inf" || str == "inf"|| str == "-inf" || str == "nan");
}

bool ScalarConverter::isFloat(const std::string& str) {
	if (isFloatPseudo(str)) return true;

	if (str[str.size() - 1] != 'f') return false;
	std::string core = str.substr(0, str.size() - 1);

	bool dot = false;
	size_t i = 0;
	if (core[i] == '+' || core[i] == '-') i++;
	if (i >= core.size()) return false;

	for (; i < core.size(); i++) {
		if (core[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!std::isdigit(core[i])) return false;
	}
	return dot;
}

bool ScalarConverter::isDouble(const std::string& str) {
	if (isDoublePseudo(str)) return true;

	bool dot = false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-') i++;
	if (i >= str.size()) return false;

	for (; i < str.size(); i++) {
		if (str[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!std::isdigit(str[i])) return false;
	}
	return dot;
}

void ScalarConverter::convert(const std::string &s) {
	double d;

	if (isChar(s)) {
		d = static_cast<double>(s[0]);
	}
	else if (isInt(s)) {
		long long val = std::strtoll(s.c_str(), NULL, 10);
		if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return;
		}
		d = static_cast<double>(val);
	}
	else if (isFloat(s)) {
		if (isFloatPseudo(s)) {
			if (s == "nanf") d = std::numeric_limits<float>::quiet_NaN();
			else if (s == "+inff" || s == "inff") d = std::numeric_limits<float>::infinity();
			else d = -std::numeric_limits<float>::infinity();
		} else {
			d = std::atof(s.c_str());
		}
	}
	else if (isDouble(s)) {
		if (isDoublePseudo(s)) {
			if (s == "nan") d = std::numeric_limits<double>::quiet_NaN();
			else if (s == "+inf" || s == "inf") d = std::numeric_limits<double>::infinity();
			else d = -std::numeric_limits<double>::infinity();
		} else {
			d = std::atof(s.c_str());
		}
	}
	else {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}

	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
