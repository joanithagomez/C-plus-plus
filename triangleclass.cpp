
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

class Triangle
{
	private:
		double sideA, sideB, sideC;
		double calcP() const;

	public:
		Triangle(double a, double b, double c);
		Triangle(double side);
		double getSideA() const;
		double getSideB() const;
		double getSideC() const;
		bool setSideA(double newA);
		bool setSideB(double newB);
		bool setSideC(double newC);
		double area() const;
		double perimeter() const;
	};
#endif

// INSIDE Triangle.cpp:
#include "Triangle.h"

Triangle::Triangle(double a, double b, double c)
{
	setSideA(a);
	setSideB(b);
	setSideC(c);
} // end constructor 1

Triangle::Triangle(double side)			////FOR 6-2a
{
	if( side > 0 ){
		sideA = sideB = sideC = side;
	}else {
		sideA = sideB = sideC = 1;
	} // end else
} // end constructor 2

double Triangle::getSideA() const{ return sideA; }

double Triangle::getSideB() const { return sideB; }

double Triangle::getSideC() const { return sideC; }

bool Triangle::setSideA(double newA)
{
	if( newA > 0 ){
		sideA= newA;
		return true;
	}// endif
	sideA=1;
	return false;
} // end setSideA

bool Triangle::setSideB(double newB)
{
	if( newB > 0 ){
		sideB= newB;
		return true;
	}// endif
	sideB=1;
	return false;
} // end setSideB

bool Triangle::setSideC(double newC)
{
	if( newC > 0 ){
		sideC= newC;
		return true;
	}// endif 	sideC=1;
	return false;
} // end setSideC

double Triangle::calcP() const				// FOR 6-2b
{
	return (sideA+sideB+sideC)/2.;
} // end calcP

double Triangle::area() const
{
	double p = calcP();  //(sideA+sideB+sideC)/2.;//FOR 6-2b

	return sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));
} // end area
double Triangle::perimeter() const			// FOR 6-2b
{
	return calcP()*2;
} // end calcP


// INSIDE main.cpp:
#include <iostream>
#include "Triangle.h" 
using namespace std;

int main()
{
	Triangle tri1(3., 4., 5.);
	Triangle tri2(10.);
	cout<<"The area of the triangle with "<<
		tri1.getSideA()<<", "<<tri1.getSideB()<<", and "
		<< tri1.getSideC()<<" = "<<tri1.area()<<endl;
	cout<<"   And the perimeter = "<<tri1.perimeter()<<endl;
	cout<<"The area of the triangle with "<<
		tri2.getSideA()<<", "<<tri2.getSideB()<<", and "
		<< tri2.getSideC()<<" = "<<tri2.area()<<endl;
	cout<<"   And the perimeter = "<<tri2.perimeter()<<endl;

	return 0;
} // end main
