#include "print.hpp"

void printChar(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || d < 0 || d > 127) {
		std::cout << "impossible" << std::endl;
	} else if (!isprint(static_cast<int>(d))) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	}
}

void printInt(double d) {
	std::cout << "int: ";
	if (std::isnan(d)
		|| d < static_cast<double>(std::numeric_limits<int>::min())
		|| d > static_cast<double>(std::numeric_limits<int>::max())) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(d) << std::endl;
	}
}

void printFloat(double d) {
	std::cout << "float: ";
	float f = static_cast<float>(d);

	if (std::isnan(f)) {
		std::cout << "nanf" << std::endl;
		return;
	}
	if (std::isinf(f)) {
		if (f > 0)
			std::cout << "inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
		return;
	}

	std::cout << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void printDouble(double d) {
	std::cout << "double: ";

	if (std::isnan(d)) {
		std::cout << "nan" << std::endl;
		return;
	}
	if (std::isinf(d)) {
		if (d > 0)
			std::cout << "inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
		return;
	}

	std::cout << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}
