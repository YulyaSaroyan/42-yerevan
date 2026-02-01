#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(const int &i)
{
	std::cout << i << " ";
}

void increment(int &i)
{
	i += 1;
}

void printString(const std::string &s)
{
	std::cout << s << " ";
}

void appendExclamation(std::string &s)
{
	s += "!";
}

int main()
{
	// --- Test 1: int array, const ---
	const int arr1[] = {1, 2, 3, 4, 5};
	std::cout << "Print const int array: ";
	iter(arr1, 5, printInt); // should print 1 2 3 4 5
	std::cout << std::endl;

	// --- Test 2: int array, non-const ---
	int arr2[] = {10, 20, 30};
	std::cout << "Original arr2: ";
	iter(arr2, 3, printInt);
	std::cout << std::endl;

	iter(arr2, 3, increment); // increment each element

	std::cout << "After increment: ";
	iter(arr2, 3, printInt);
	std::cout << std::endl;

	// --- Test 3: string array, non-const ---
	std::string arr3[] = {"hello", "world"};
	std::cout << "Original strings: ";
	iter(arr3, 2, printString);
	std::cout << std::endl;

	iter(arr3, 2, appendExclamation);

	std::cout << "After append: ";
	iter(arr3, 2, printString);
	std::cout << std::endl;

	// --- Test 4: string array, const ---
	const std::string arr4[] = {"foo", "bar"};
	std::cout << "Const strings: ";
	iter(arr4, 2, printString);
	std::cout << std::endl;

	return 0;
}
