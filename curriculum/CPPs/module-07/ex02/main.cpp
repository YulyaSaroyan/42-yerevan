#include <iostream>
#include "Array.hpp"

int main()
{
	std::cout << "--- Testing default constructor ---" << std::endl;
	Array<int> a1;
	std::cout << "Size: " << a1.size() << std::endl;

	std::cout << "\n--- Testing size constructor ---" << std::endl;
	Array<int> a2(5);
	for (size_t i = 0; i < a2.size(); ++i)
		a2[i] = i * 10;

	for (size_t i = 0; i < a2.size(); ++i)
		std::cout << a2[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- Testing copy constructor ---" << std::endl;
	Array<int> a3(a2);
	a3[0] = 100; // modify copy
	std::cout << "Original a2[0]: " << a2[0] << " | Copy a3[0]: " << a3[0] << std::endl;

	std::cout << "\n--- Testing assignment operator ---" << std::endl;
	Array<int> a4;
	a4 = a2;
	a4[1] = 200; // modify copy
	std::cout << "Original a2[1]: " << a2[1] << " | Assigned a4[1]: " << a4[1] << std::endl;

	std::cout << "\n--- Testing const operator[] ---" << std::endl;

	const Array<int> a5(a2); // const copy

	// Reading is allowed (calls const operator[])
	for (size_t i = 0; i < a5.size(); ++i)
		std::cout << a5[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- Testing out of bounds ---" << std::endl;
	try {
		std::cout << a2[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing with std::string ---" << std::endl;
	Array<std::string> arrStr(3);
	arrStr[0] = "Hello";
	arrStr[1] = "World";
	arrStr[2] = "!";
	for (size_t i = 0; i < arrStr.size(); ++i)
		std::cout << arrStr[i] << " ";
	std::cout << std::endl;

	return 0;
}
