#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
using namespace std;
#include <cmath>

class Triangle
{
	private:
		double sideA, sideB, sideC;
		double calcP() const;			// FOR 6-2 b

	public:
		Triangle() { sideA = sideB = sideC = 1; }
		Triangle(double a, double b, double c); // FOR 6-2a
		Triangle(double side); 			// FOR 6-2a
		//Triangle(const Triangle &source);// only for example
		double getSideA() const;
		double getSideB() const;
		double getSideC() const;
		bool setSideA(double newA);
		bool setSideB(double newB);
		bool setSideC(double newC);
		double area() const;
		double perimeter() const; // FOR 6-2b

		bool operator <(const Triangle& right) const;
		bool operator ==(const Triangle& right) const;
		bool operator >(const Triangle& right) const;

		friend ostream& operator<<(ostream &os,const Triangle& tri);
};
#endif
