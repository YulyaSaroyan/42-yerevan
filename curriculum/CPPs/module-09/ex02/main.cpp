#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pm;
		pm.parseInput(argc, argv);
		pm.run();
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
	}
	return 0;
}
