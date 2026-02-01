#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int fixedPoint;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed(const int integer);
	Fixed(const float floatNumber);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);

#endif
