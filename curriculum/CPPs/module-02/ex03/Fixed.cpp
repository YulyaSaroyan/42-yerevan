#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPoint(0) {}

Fixed::Fixed(const int integer) {
	this->setRawBits(integer << this->fractionalBits);
}

Fixed::Fixed(const float floatingNumber) {
	this->setRawBits(roundf(floatingNumber * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &other) const {
	return this->fixedPoint > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->fixedPoint < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->fixedPoint >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->fixedPoint <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->fixedPoint == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->fixedPoint != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed temp;

	temp.setRawBits(this->fixedPoint + other.getRawBits());
	return temp;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed temp;

	temp.setRawBits(this->getRawBits() - other.getRawBits());
	return temp;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed temp;

	temp.setRawBits(this->fixedPoint * (other.getRawBits() >> Fixed::fractionalBits));
	return temp;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed temp;

	temp.setRawBits((this->fixedPoint << Fixed::fractionalBits) / other.getRawBits());
	return temp;
}

Fixed Fixed::operator++() {
	++this->fixedPoint;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp;

	temp.setRawBits(this->fixedPoint++);
	return temp;
}

Fixed Fixed::operator--() {
	--this->fixedPoint;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp;

	temp.setRawBits(this->fixedPoint--);
	return temp;
}

Fixed &Fixed::min(Fixed &other1, Fixed &other2) {
	return (other1 < other2) ? other1 : other2;
}

const Fixed &Fixed::min(const Fixed &other1, const Fixed &other2) {
	return (other1 < other2) ? other1 : other2;
}

Fixed &Fixed::max(Fixed &other1, Fixed &other2) {
	return (other1 > other2) ? other1 : other2;
}

const Fixed &Fixed::max(const Fixed &other1, const Fixed &other2) {
	return (other1 > other2) ? other1 : other2;
}

std::ostream &operator<<(std::ostream &cout, const Fixed &other) {
	cout << other.toFloat();
	return cout;
}
