#include <iostream>
#include <string>
#include <cctype>

std::string touppercase(std::string word)
{
	std::string capitalized = word;

	for (unsigned long i = 0; i < word.length(); ++i)
		capitalized[i] = std::toupper(static_cast<unsigned char>(word[i]));

	return capitalized;
}

int main(int argc, char** argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < argc; ++i)
		std::cout << touppercase(argv[i]);

	std::cout << std::endl;

	return 0;
}
