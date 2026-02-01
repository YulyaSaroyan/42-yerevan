#include <iostream>
#include "Point.hpp"

void testBsp(const Point &a, const Point &b, const Point &c, const Point &p, const std::string &label)
{
	std::cout << label << " -> "
			  << "Point(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ") in triangle? "
			  << std::boolalpha << bsp(a, b, c, p)
			  << std::endl;
}

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << "\n===========================" << std::endl;
	std::cout << "   Basic triangle tests" << std::endl;
	std::cout << "===========================\n" << std::endl;

	testBsp(a, b, c, Point(3, 3), "Inside (center area)");     // ✅ inside
	testBsp(a, b, c, Point(1, 1), "Inside (close to edge)");   // ✅ inside
	testBsp(a, b, c, Point(9, 1), "Outside (right side)");     // ❌ outside
	testBsp(a, b, c, Point(10, 10), "Outside (far away)");     // ❌ outside

	std::cout << "\n===========================" << std::endl;
	std::cout << "   Edge & vertex cases" << std::endl;
	std::cout << "===========================\n" << std::endl;

	testBsp(a, b, c, Point(0, 0), "On vertex A");              // ❌ vertex
	testBsp(a, b, c, Point(10, 0), "On vertex B");             // ❌ vertex
	testBsp(a, b, c, Point(0, 10), "On vertex C");             // ❌ vertex
	testBsp(a, b, c, Point(5, 0), "On edge AB");               // ❌ edge
	testBsp(a, b, c, Point(0, 5), "On edge AC");               // ❌ edge
	testBsp(a, b, c, Point(2, 8), "On edge BC? (outside area)");// ❌ edge

	std::cout << "\n===========================" << std::endl;
	std::cout << "   Negative coordinates" << std::endl;
	std::cout << "===========================\n" << std::endl;

	Point Aneg(-5, -5);
	Point Bneg(5, -5);
	Point Cneg(0, 5);

	testBsp(Aneg, Bneg, Cneg, Point(0, 0), "Inside (center negative triangle)"); // ✅ inside
	testBsp(Aneg, Bneg, Cneg, Point(-5, -5), "On vertex Aneg");                  // ❌ vertex
	testBsp(Aneg, Bneg, Cneg, Point(6, -6), "Outside (far right)");              // ❌ outside

	std::cout << "\n===========================" << std::endl;
	std::cout << "   Degenerate / flat triangles" << std::endl;
	std::cout << "===========================\n" << std::endl;

	Point flatA(0, 0);
	Point flatB(5, 0);
	Point flatC(10, 0);

	testBsp(flatA, flatB, flatC, Point(5, 0), "Flat triangle edge point");   // ❌ edge
	testBsp(flatA, flatB, flatC, Point(3, 1), "Flat triangle above edge");   // ❌ outside (triangle has 0 area)

	std::cout << "\n✅ Done testing all cases." << std::endl;

	return 0;
}
