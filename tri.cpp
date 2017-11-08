#include <iostream>
#include <cmath>
using namespace std;

// Triangle class declaration.
class Triangle
{
private:
  double a;
  double b;
  double c;
  double halfPerimeter() const;

public:
  bool operator<(const Triangle &right);
  bool operator==(const Triangle &right);
  friend ostream& operator<<(ostream& os, const Triangle &right);


  //Constructor 1
  Triangle(double newSideA, double newSideB, double newSideC)
  {
    setSideA(newSideA);
    setSideB(newSideB);
    setSideC(newSideC);
  }

  //Constructor 2
  Triangle(double side)
  {
    a = side;
    b = side;
    c = side;
  }

  void setSideA(double);
  void setSideB(double);
  void setSideC(double);
  double getSideA() const;
  double getSideB() const;
  double getSideC() const;
  double getArea() const;
  double getPerimeter() const;


};

//*************************************************************
// Overloaded << operator. Prints the three sides of the triangle
//*************************************************************

ostream& operator<<(ostream& os, const Triangle &right)
{
  os <<  "(" << right.a << ", "<< right.b <<", "<< right.c << ")";
  return os;
}

//************************************************************
// Overloaded < operator. Returns bool value                *
//************************************************************

bool Triangle::operator<(const Triangle &right)
{
  bool status;

  if(this->getArea() < right.getArea()){

    status = true;
  }
  else if(this->getArea() == right.getArea()){

    if(this->getPerimeter() < right.getPerimeter())
      status = true;
    else
      status = false;
  }
  else
    status = false;


  return status;
  }

  //*************************************************************
  // Overloaded == operator. Returns true if the current object *
  // is set to a value equal to that of right.                  *
  //*************************************************************

  bool Triangle::operator==(const Triangle &right)
  {
    bool status;

    if(a  == right.a && b == right.b && c == right.c  )
      status = true;
    else
      status = false;
    return status;

    }


//**************************************************
// Calculates half perimeter
//**************************************************

double Triangle::halfPerimeter() const
{
  return (a + b + c)/2.0;
}
//**************************************************
// setSideA assigns a value to the 'a' member.   *
//**************************************************

void Triangle::setSideA(double sideA)
{
  if(sideA <= 0)
  {
    a = 1;
  }
  else
  {
    a = sideA;
  }
}

//**************************************************
// setSideB assigns a value to the 'b' member.   *
//**************************************************

void Triangle::setSideB(double sideB)
{
  if(sideB <= 0)
    b = 1;

  else
    b = sideB;
}

//**************************************************
// setSideC assigns a value to the 'c' member.   *
//**************************************************

void Triangle::setSideC(double sideC)
{
  if(sideC <= 0)
    c = 1;

  else
    c = sideC;
}

//*****************************************************
// getSideA returns the value of side a
//*****************************************************

double Triangle::getSideA() const
{
  return a;
}

//*****************************************************
// getSideB returns the value of side b
//*****************************************************

double Triangle::getSideB() const
{
  return b;
}

//*****************************************************
// getSideC returns the value of side c
//*****************************************************

double Triangle::getSideC() const
{
  return c;
}

//*****************************************************
// getArea returns the area of the triangle using Heron's formula *
//*****************************************************

double Triangle::getArea() const
{
  double rho = halfPerimeter();
  return sqrt(rho * (rho-a) * (rho-b) * (rho - c));
}

//*****************************************************
// getPerimeter returns the perimeter of the triangle *
//*****************************************************

double Triangle::getPerimeter() const
{
  double rho = halfPerimeter();
  return 2 * rho;
}


//*****************************************************
// Function main                                      *
//*****************************************************


int main()
{
  Triangle obj1(3.0, 4.0, 5.0);
  Triangle obj2(10);
  Triangle obj3(3.0, 4.0, 5.0);


  //Perimeter of obj1: (3.0, 4.0, 5.0) <>

  cout << "Perimeter of obj1: " << obj1 << ": ";
  cout << obj1.getPerimeter() << endl;
  cout << "Perimeter of obj2: " << obj2 <<": ";
  cout << obj2.getPerimeter() << endl;

  if(obj1 < obj2)
  {
    cout << "Obj1 is smaller." << endl;
  }
  else
  {
    cout << "Obj2 is bigger."<< endl;
  }

  }

  if(obj1 == obj3)
  {
    cout << "Triangles have equal sides.";
  }
  // Display area
  cout << "\nArea of obj1: " ;
  cout << obj1.getArea() << endl;
  cout << "Area of obj2: ";
  cout << obj2.getArea() << endl;

}

/* OUTPUT:
Perimeter of obj1: 12
Perimeter of obj1: 30

Area of obj1: 6
Area of obj2: 43.3013

*/
