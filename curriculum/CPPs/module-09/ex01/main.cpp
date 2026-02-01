#include "RTN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		rtn(argv[1]);
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
