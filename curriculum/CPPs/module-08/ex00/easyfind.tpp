#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator found = std::find(container.begin(), container.end(), value);

	if (found != container.end())
		return found;
	throw std::runtime_error("Value not found in container");
}
