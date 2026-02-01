#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <sys/time.h>
#include <algorithm>
#include <iomanip>

static double getTime()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int ac, char **av)
{
	if (ac < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < ac; i++)
	{
		std::string s(av[i]);

		if (s.empty())
			throw std::runtime_error("Error");

		for (size_t j = 0; j < s.length(); j++)
		{
			if (!isdigit(s[j]))
				throw std::runtime_error("Error");
		}

		long num = atol(av[i]);

		if (num <= 0 || num > INT_MAX)
			throw std::runtime_error("Error");

		_vector.push_back((int)num);
		_deque.push_back((int)num);
	}
}

void PmergeMe::fordJohnsonVector(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<std::pair<int,int> > pairs;
	int leftover = -1;

	// Step 1: Make pairs
	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];

		if (a > b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}

	if (arr.size() % 2 == 1)
		leftover = arr.back();

	// Step 2: Collect big values
	std::vector<int> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].second);

	// Step 3: Sort big values recursively
	fordJohnsonVector(bigs);

	// Step 4: Insert small values
	for (size_t i = 0; i < pairs.size(); i++)
	{
		int small = pairs[i].first;
		std::vector<int>::iterator pos =
			std::lower_bound(bigs.begin(), bigs.end(), small);
		bigs.insert(pos, small);
	}

	// Step 5: Insert leftover
	if (leftover != -1)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(bigs.begin(), bigs.end(), leftover);
		bigs.insert(pos, leftover);
	}

	arr = bigs;
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::deque<std::pair<int,int> > pairs;
	int leftover = -1;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];

		if (a > b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}

	if (arr.size() % 2 == 1)
		leftover = arr.back();

	std::deque<int> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].second);

	fordJohnsonDeque(bigs);

	for (size_t i = 0; i < pairs.size(); i++)
	{
		int small = pairs[i].first;
		std::deque<int>::iterator pos =
			std::lower_bound(bigs.begin(), bigs.end(), small);
		bigs.insert(pos, small);
	}

	if (leftover != -1)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(bigs.begin(), bigs.end(), leftover);
		bigs.insert(pos, leftover);
	}

	arr = bigs;
}

void PmergeMe::run()
{
	printBefore();

	double startVec = getTime();
	sortVector();
	double endVec = getTime();

	double startDeq = getTime();
	sortDeque();
	double endDeq = getTime();

	printAfter(_vector);

	std::cout << std::fixed << std::setprecision(5);

	std::cout << "Time to process a range of "
			  << _vector.size()
			  << " elements with std::vector : "
			  << (endVec - startVec)
			  << " us" << std::endl;

	std::cout << "Time to process a range of "
			  << _deque.size()
			  << " elements with std::deque : "
			  << (endDeq - startDeq)
			  << " us" << std::endl;
}

void PmergeMe::sortVector()
{
	fordJohnsonVector(_vector);
}

void PmergeMe::sortDeque()
{
	fordJohnsonDeque(_deque);
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfter(const std::vector<int> &sorted) const
{
	std::cout << "After: ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
}
