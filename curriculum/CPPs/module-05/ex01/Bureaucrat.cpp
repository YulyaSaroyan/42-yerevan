#include "Bureaucrat.hpp"

// should never be called
Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	validateGrade(grade);

	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if(this != &other) {
		this->grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::increment() {
	validateGrade(this->grade - 1);
	this->grade--;
}

void Bureaucrat::decrement() {
	validateGrade(this->grade + 1);
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat: grade too low";
}

void Bureaucrat::validateGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << this->name << " couldn’t sign " << f.getName()
				  << " because " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
