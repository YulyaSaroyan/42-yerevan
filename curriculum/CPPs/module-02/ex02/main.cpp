#include <iostream>
#include "Fixed.hpp"

int main() {
	std::cout << "==== Basic increment/decrement tests ====" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "Initial a: " << a << std::endl;
	std::cout << "Pre-increment ++a: " << ++a << std::endl;
	std::cout << "After pre-increment a: " << a << std::endl;
	std::cout << "Post-increment a++: " << a++ << std::endl;
	std::cout << "After post-increment a: " << a << std::endl;

	std::cout << "\n==== Fixed-point arithmetic ====" << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	std::cout << "\n==== Comparison operators ====" << std::endl;
	Fixed c(3.14f);
	Fixed d(2.71f);

	std::cout << c << " > " << d << " ? " << (c > d) << std::endl;
	std::cout << c << " < " << d << " ? " << (c < d) << std::endl;
	std::cout << c << " >= " << d << " ? " << (c >= d) << std::endl;
	std::cout << c << " <= " << d << " ? " << (c <= d) << std::endl;
	std::cout << c << " == " << d << " ? " << (c == d) << std::endl;
	std::cout << c << " != " << d << " ? " << (c != d) << std::endl;

	std::cout << "\n==== Min / Max functions ====" << std::endl;
	std::cout << "Max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "Min(a, b) = " << Fixed::min(a, b) << std::endl;

	Fixed e(1.5f);
	Fixed f(2.5f);

	std::cout << "Max(e, f) = " << Fixed::max(e, f) << std::endl;
	std::cout << "Min(e, f) = " << Fixed::min(e, f) << std::endl;

	std::cout << "\n==== Postfix / Prefix increment edge tests ====" << std::endl;
	Fixed g(0);
	std::cout << "g initial: " << g << std::endl;
	std::cout << "++g: " << ++g << std::endl;
	std::cout << "g++: " << g++ << std::endl;
	std::cout << "g after g++: " << g << std::endl;

	std::cout << "\n==== Division edge case ====" << std::endl;
	Fixed h(10);
	Fixed i(2);
	Fixed j(0.5f);

	std::cout << "h / i = " << h / i << std::endl;   // 10 / 2 = 5
	std::cout << "h / j = " << h / j << std::endl;   // 10 / 0.5 = 20

	return 0;
}
