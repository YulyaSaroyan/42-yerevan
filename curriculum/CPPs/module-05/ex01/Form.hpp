#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string name;
	const int signGrade;
	const int execGrade;
	bool isSigned;

	void validateGrade(int g);
public:
	Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	Form(const std::string name, const int signGrade, const int execGrade);
	~Form();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
