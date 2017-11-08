// INSIDE Triangle.cpp:
#include "Triangle.h"

Triangle::Triangle(double a, double b, double c)//FOR 6-2a
{
	setSideA(a);// NOT sideA = a;
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

// "this" keyword refers to the object you're in
bool Triangle::operator <(const Triangle& right) const
{
	bool isLessThan = this->area() < right.area();//compare areas

	if( this->area() == right.area() ) //if equal, compare per.
			isLessThan = this->perimeter() < right.perimeter();
	return isLessThan;

}

bool Triangle::operator ==(const Triangle& right) const
{
	return sideA==right.sideA && sideB==right.sideB
			&& sideC==right.sideC;
}

bool Triangle::operator>(const Triangle& right) const
{
	return right < *this;
}


// cout is a type of ostream
// ofstream is also a type of ostream

ostream& operator<<(ostream &os,
				const Triangle& tri)
{
	os << "1st side=" << tri.sideA
		<< ", 2nd side=" << tri.sideB
		<< ", 3rd side=" << tri.sideC;
	return os;
}
