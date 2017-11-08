//Joanitha Christle Gomez
// Lab 4-2
#include <iostream>
using namespace std;

struct Date
{
  string monthName;         // Name of month
  int date;
  int month;
  int year;

};

void readDate(Date &day)
{
	cout << "Enter date: " ;
	cin >> day.date ;
	cout << "Enter month: " ;
	cin >> day.month;
	cout << "Enter year: ";
	cin >> day.year;

	 switch(day.month)
  {
    case 1 : day.monthName = "January";
      break;
    case 2 : day.monthName = "February";
      break;
    case 3 : day.monthName = "March";
      break;
    case 4 : day.monthName = "April";
      break;
    case 5 : day.monthName = "May";
      break;
    case 6 : day.monthName = "June";
      break;
    case 7 : day.monthName = "July";
      break;
    case 8 : day.monthName = "August";
      break;
    case 9 : day.monthName = "September";
      break;
    case 10: day.monthName = "October";
      break;
    case 11: day.monthName = "November";
      break;
    case 12: day.monthName = "December";

    default: day.monthName = "Invalid month" ;
    break;
  }

}

struct Person
{
     string lastName;
     string firstName;
     Date birthdate;
};


void displayPerson(const Person &pers)
{
    cout << pers.lastName << endl;
    cout << pers.firstName << endl;
    cout << pers.birthdate.month << "/" << pers.birthdate.date << "/" << pers.birthdate.year << endl ;
}

int main()
{
  Person p;
  Date day;
  readDate(day);
  p.firstName = "Jo";
  p.lastName = "Gomez";
  p.birthdate = day;

  displayPerson(p);

}

/* Output :
Gomez
Jo
3/1/1999
*/
