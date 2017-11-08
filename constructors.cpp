#include <iostream>
using namespace std;



class Student {
  string name;
  string grade;
  static int count;

public:

  Student() {
    cout << "constructing Student " << count << endl;
    count++;
    name = "Jo";
    grade = "A";
  }

  Student(string name) {
    cout << "one arg constructor" << endl;
    this->name = name;
  }
};

int Student::count = 0;

int main() {
  Student foo;

  //Student list[10];

  Student *bar;

  bar = new Student("Jo");

/*
CHANGE the constructor with parameters and
mutator for the birthdate's year to check if the parameter for the birthdate's year
> 0 and <= current year (YOU MUST USE THE CODE OR PRIVATE FUNCTION TO
GET THE CURRENT YEAR SHOWN IN A. BELOW). CHANGE the speak function to
write to an ostream &. ADD to the Pet class a member functions overloading
operator < , operator >, operator == and operator != (could call ==) that
compares the names, then the birthdates using the overloaded <,>,== in the
Date class (if the names are the same).
  Student foo;
  Student bar(foo);

  Student baz;

  baz = bar;

  int x = 0;

  int y = 1;

  y = x;
*/

}
