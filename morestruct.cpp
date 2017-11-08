
#include <iostream>

using namespace std;

struct Student {
    const char *name;
    float gpa;
    const char *major;
};

void printStudent(Student s) {
  cout << "{" << s.name << ", " << s.gpa << ", " << s.major << "}" << endl;
}

// returns the number of students in the passed list that have a GPA greater than
// or equal to the passed `gpa` value
int countStudentsWithGPA(Student* input, int length, float gpa) {
  int count = 0;
  for(int i = 0; i < length; i++)
  {
    if((input[i]).gpa >= gpa)
    count++;
  }
  return count;
}

// returns the number of students who are in the specified major
// or equal to the passed `gpa` value
int countStudentsInMajor(Student *input, int length, string major) {
  int count = 0;
  for(int i = 0; i < length; i++)
  {
    if(input[i].major == major){
      count++;
    }
  }
  return count;
}

int findHighestNumber(int *input, int length) {
    int high = 0;
    for(int i = 0; i < length; i++) {
      if(input[i] > high) {
        high = input[i];
      }
    }

    return high;
}


// find the student with the highest GPA, in the passed list
Student findTopScorer(Student *input, int length) {
  Student high;
  high.gpa = 0;

  for(int i = 0; i < length; i++)
  {
    if(input[i].gpa > high.gpa)
    {
       high = input[i];
    }
  }
  return high;
}

int main() {
  Student students[] = {
    {"Justin", 2.0, "Psych"},
    {"Arianna", 3.5, "Lit"},
    {"Selena", 3.65, "History"},
    {"Iggy", 3.75, "History"},
    {"Bruno", 2.75, "History"}
  };

  const int SIZE = 5;

  cout << "Students with GPA >= 2.0: " << countStudentsWithGPA(students, SIZE, 2.0) << endl;
  cout << "Students with GPA >= 3.5: " << countStudentsWithGPA(students, SIZE, 3.5) << endl;
  cout << "Students with GPA >= 3.75: " << countStudentsWithGPA(students, SIZE, 3.75) << endl;
  cout << "Students with major = Lit: " << countStudentsInMajor(students, SIZE, "Lit") << endl;
  cout << endl << endl;

  cout << "Topper:" << endl;
  printStudent(findTopScorer(students, SIZE));
return 0;
}
