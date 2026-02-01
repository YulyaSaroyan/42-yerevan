#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::srand(std::time(0));

	Base* base = generate();

	std::cout << "identify(*ptr): ";
	identify(base);

	std::cout << "identify(ref): ";
	identify(*base);

	delete base;
}
