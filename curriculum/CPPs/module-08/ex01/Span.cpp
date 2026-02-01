#include "Span.hpp"

#include <iostream>

Span::Span(unsigned int N) {
	this->_maxSize = N;
	this->_numbers.reserve(N);
}

Span::Span(const Span& other) {
	this->_maxSize = other._maxSize;
	this->_numbers = other._numbers;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_maxSize) {
		throw std::runtime_error("Span is already full");
	}
	this->_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];

	for (size_t i = 1; i < sorted.size() - 1; i++) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	return sorted.back() - sorted.front();
}
