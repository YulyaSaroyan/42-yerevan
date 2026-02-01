#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
	(void)other;
	return *this;
}

const Fixed Point::getX() const {
	return this->x;
}

const Fixed Point::getY() const {
	return this->y;
}

Point::~Point() {}
