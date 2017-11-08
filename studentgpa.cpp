#include <iostream>
using namespace std;

class Person {
protected:
  string name;
public:
  Person(string name="");
};

Person::Person(string name) {
  this->name = name;
}

class Student : public Person {

  string gpa;
  Course course;
  friend void print(Student s);
  friend Student operator+(Student&,Student&);
  friend ostream& operator<<(ostream& in, Student& s);

  public:
  Student(string name = "", string gpa = "");

  string getName() { return name;}
  string getGPA() { return gpa;}

  void display() {
    cout << name << ":" << gpa << endl;
  }

  bool operator<(Student& other) {
    return this->gpa < other.gpa;
  }

  bool operator==(Student& other) {
    return this->gpa == other.gpa && this->name == other.name;
  }

  ~Student() {
    cout << "destructor called for " << name << endl;
  }
};


Student::Student(string name, string gpa, string courseName) : name(name) {
  this->gpa = gpa;
}

void print(int num) {
  cout << num << endl;
}

void print(Student s) {
  cout << "(" << s.name << ":" << s.gpa << ")" <<endl;
}

Student operator+(Student& lhs, Student& rhs) {
  Student sum;
  sum.name = lhs.name + " " + rhs.name;
  sum.gpa = lhs.gpa + rhs.gpa;
  return sum;
}

ostream& operator<<(ostream& in, Student& s) {
    in << s.name << ":" << s.gpa;
    return in;
}

void doStuff() {
  Student jo;
}

int main() {

  cout << "Hello 1" << endl;
  doStuff();
  cout << "Hello 2" << endl;

  Student foo("jo", "a");

}
