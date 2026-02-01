#include <iostream>
#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
	std::cout << "==== BASIC TESTS ====" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\n==== FORWARD ITERATION ====" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	for (; it != ite; ++it)
		std::cout << *it << std::endl;

	std::cout << "\n==== CONST ITERATOR ====" << std::endl;
	const MutantStack<int> constStack = mstack;
	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();

	for (; cit != cite; ++cit)
		std::cout << *cit << std::endl;

	std::cout << "\n==== REVERSE ITERATION ====" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	for (; rit != rite; ++rit)
		std::cout << *rit << std::endl;

	std::cout << "\n==== CONST REVERSE ITERATION ====" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = constStack.rend();

	for (; crit != crite; ++crit)
		std::cout << *crit << std::endl;

	std::cout << "\n==== COPY CONSTRUCTOR TEST ====" << std::endl;
	MutantStack<int> copyStack(mstack);

	for (MutantStack<int>::iterator i = copyStack.begin(); i != copyStack.end(); ++i)
		std::cout << *i << std::endl;

	std::cout << "\n==== ASSIGNMENT OPERATOR TEST ====" << std::endl;
	MutantStack<int> assignStack;
	assignStack = mstack;

	for (MutantStack<int>::iterator i = assignStack.begin(); i != assignStack.end(); ++i)
		std::cout << *i << std::endl;

	std::cout << "\n==== COMPARISON: std::list BEHAVIOR ====" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	for (std::list<int>::iterator li = lst.begin(); li != lst.end(); ++li)
		std::cout << *li << std::endl;

	std::cout << "\n==== USING ANOTHER CONTAINER: std::vector ====" << std::endl;
	MutantStack<int, std::vector<int> > vecStack;

	vecStack.push(10);
	vecStack.push(20);
	vecStack.push(30);

	for (MutantStack<int, std::vector<int> >::iterator i = vecStack.begin(); i != vecStack.end(); ++i)
		std::cout << *i << std::endl;

	std::cout << "\n==== EMPTY STACK ITERATION ====" << std::endl;
	MutantStack<int> empty;

	if (empty.begin() == empty.end())
		std::cout << "Empty stack iterators OK" << std::endl;

	return 0;
}
