#include "Point.hpp"

static Fixed cross_product(const Point &a, const Point &b, const Point &p) {
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
	     - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1 = cross_product(point, a, b);
	Fixed d2 = cross_product(point, b, c);
	Fixed d3 = cross_product(point, c, a);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	// Exclude edges (on vertex or line)
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	// Inside if all are same sign (no mix)
	return !(has_neg && has_pos);
}
