#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span sp1(10000);

		int arr[] = {10, 20, 21, 30, 40};
		sp1.addNumbers(arr, arr + 5);

		std::cout << "sp1 shortest: " << sp1.shortestSpan() << std::endl;
		std::cout << "sp1 longest: " << sp1.longestSpan() << std::endl;

		Span sp2(10000);
		std::vector<int> vec(10000);
		for (int i = 0; i < 10000; i++)
			vec[i] = i * 2;
		sp2.addNumbers(vec.begin(), vec.end());

		std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
