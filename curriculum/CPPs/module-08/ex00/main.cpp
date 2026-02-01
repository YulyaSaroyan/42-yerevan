#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void printVector(const std::vector<int>& v) {
	std::cout << "Vector content: ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void printList(const std::list<int>& lst) {
	std::cout << "List content: ";
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void printDeque(const std::deque<int>& dq) {
	std::cout << "Deque content: ";
	for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void testVector() {
	std::cout << "===== Testing std::vector =====" << std::endl;

	std::vector<int> v;
	v.push_back(3);
	v.push_back(7);
	v.push_back(21);

	printVector(v);

	try {
		std::cout << "Searching for 7..." << std::endl;
		std::vector<int>::iterator it = easyfind(v, 7);
		std::cout << "✔ Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "✘ Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "Searching for 42..." << std::endl;
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "✔ Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "✘ Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void testList() {
	std::cout << "===== Testing std::list =====" << std::endl;

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	printList(lst);

	try {
		std::cout << "Searching for 20..." << std::endl;
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "✔ Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "✘ Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "Searching for 999..." << std::endl;
		std::list<int>::iterator it = easyfind(lst, 999);
		std::cout << "✔ Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "✘ Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void testDeque() {
	std::cout << "===== Testing std::deque =====" << std::endl;

	std::deque<int> dq;
	dq.push_back(100);
	dq.push_back(200);
	dq.push_back(300);

	printDeque(dq);

	try {
		std::cout << "Searching for 300..." << std::endl;
		std::deque<int>::iterator it = easyfind(dq, 300);
		std::cout << "✔ Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "✘ Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "Searching for -1..." << std::endl;
		std::deque<int>::iterator it = easyfind(dq, -1);
		std::cout << "✔ Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "✘ Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void testEmptyContainer() {
	std::cout << "===== Testing empty container =====" << std::endl;

	std::vector<int> empty;

	try {
		std::cout << "Searching for 1 in empty container..." << std::endl;
		std::vector<int>::iterator it = easyfind(empty, 1);
		std::cout << "✔ Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "✘ Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

int main() {
	testVector();
	testList();
	testDeque();
	testEmptyContainer();

	return 0;
}
