#include "AForm.hpp"

AForm::AForm() : name("Default"), signGrade(100), execGrade(50), isSigned(false) {}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) :
	name(name),
	signGrade(signGrade),
	execGrade(execGrade),
	isSigned(false)
{
	validateGrade(signGrade);
	validateGrade(execGrade);
}

AForm::AForm(const AForm &other) :
	name(other.getName()),
	signGrade(other.getSignGrade()),
	execGrade(other.getExecGrade()),
	isSigned(other.getIsSigned())
{}

AForm &AForm::operator=(const AForm &other) {
	if(this != &other) {
		this->isSigned = other.getIsSigned();
	}
	return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm: grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "AForm: form  not signed";
}

const std::string AForm::getName() const {
	return this->name;
}

int AForm::getSignGrade() const {
	return this->signGrade;
}

int AForm::getExecGrade() const {
	return this->execGrade;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

void AForm::validateGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

void AForm::canExecute(const Bureaucrat& executor) const {
	if (!getIsSigned()) throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade()) throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << f.getName() << ", form signed grade " << f.getSignGrade() << ", form exec grade " << f.getExecGrade() << ", form is signed " << f.getIsSigned() << ".";
	return os;
}
