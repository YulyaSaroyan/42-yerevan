#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	const std::string* getIdeas() const;
	const std::string getIdea(int index) const;
	std::string setIdea(int index, std::string value);
};

#endif
