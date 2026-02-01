#include "RTN.hpp"

static bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static int apply(int first, int second, char op)
{
	if (op == '+') return first + second;
	if (op == '-') return first - second;
	if (op == '*') return first * second;

	if (op == '/')
	{
		if (second == 0)
			throw std::runtime_error("Error");
		return first / second;
	}

	throw std::runtime_error("Error");
}

void rtn(std::string expression) {
	std::istringstream iss(expression);
	std::stack<int> st;
	char token;

	while (iss >> token)
	{
		if (std::isdigit(token))
		{
			st.push(token - '0');
		}
		else if (isOperator(token))
		{
			if (st.size() < 2)
				throw std::runtime_error("Error");

			int second = st.top(); st.pop();
			int first  = st.top(); st.pop();

			int result = apply(first, second, token);
			st.push(result);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (st.size() != 1)
		throw std::runtime_error("Error");

	std::cout << st.top() << std::endl;
}
