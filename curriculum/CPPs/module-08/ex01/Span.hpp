#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
	Span();
	unsigned int _maxSize;
	std::vector<int> _numbers;
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end) {
		int size = std::distance(begin, end);
		if (_numbers.size() + size > _maxSize )
			throw std::runtime_error("No place for new members");

		_numbers.insert(_numbers.end(), begin, end);
	}
	int shortestSpan() const;
	int longestSpan() const;
};

#endif
