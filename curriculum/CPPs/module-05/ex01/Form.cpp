#include "Form.hpp"

Form::Form() : name("Default"), signGrade(100), execGrade(50), isSigned(false) {}

Form::Form(const std::string name, const int signGrade, const int execGrade) :
	name(name),
	signGrade(signGrade),
	execGrade(execGrade),
	isSigned(false)
{
	validateGrade(signGrade);
	validateGrade(execGrade);
}

Form::Form(const Form &other) :
	name(other.getName()),
	signGrade(other.getSignGrade()),
	execGrade(other.getExecGrade()),
	isSigned(other.getIsSigned())
{}

Form &Form::operator=(const Form &other) {
	if(this != &other) {
		this->isSigned = other.getIsSigned();
	}
	return *this;
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: grade too low";
}

const std::string Form::getName() const {
	return this->name;
}

int Form::getSignGrade() const {
	return this->signGrade;
}

int Form::getExecGrade() const {
	return this->execGrade;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

void Form::validateGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << f.getName() << ", form signed grade " << f.getSignGrade() << ", form exec grade " << f.getExecGrade() << ", form is signed " << f.getIsSigned() << ".";
	return os;
}
