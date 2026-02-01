#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
private:
	const std::string name;
	int grade;
	Bureaucrat();

	void validateGrade(int g);
public:
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	const std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(AForm& f);
	void executeForm(const AForm& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#include "AForm.hpp"
#endif
