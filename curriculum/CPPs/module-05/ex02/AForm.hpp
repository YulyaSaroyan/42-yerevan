#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string name;
	const int signGrade;
	const int execGrade;
	bool isSigned;

	void validateGrade(int g);
public:
	AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	AForm(const std::string name, const int signGrade, const int execGrade);
	virtual ~AForm();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};

	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat& b);

	void canExecute(const Bureaucrat& executor) const;
	virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
