#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int>  _deque;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseInput(int ac, char **av);
	void run();

private:
	void sortVector();
	void sortDeque();

	void fordJohnsonVector(std::vector<int> &arr);
	void fordJohnsonDeque(std::deque<int> &arr);

	void printBefore() const;
	void printAfter(const std::vector<int> &sorted) const;
};

#endif
