#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint= integer << this->fractionalBits;
}

Fixed::Fixed(const float floatingNumber) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(floatingNumber * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

float Fixed::toFloat() const {
	return (float)this->fixedPoint / (1 << this->fractionalBits);
}

int Fixed::toInt() const {
	return this->fixedPoint >> this->fractionalBits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& other) {
	stream << other.toFloat();
	return stream;
}
