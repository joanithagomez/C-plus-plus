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

int main()
{
  Date day;                 // Defining a structure variable
  cout << "Enter date: ";
  cin >> day.date ;         // get the date
  cout << "Enter month: ";
  cin >> day.month;         // get the month
  cout << "Enter year: ";
  cin >> day.year;          // get the year

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

    default: cout << "Sorry month not found!";
    break;
  }
  cout << "Name of month: " << day.monthName << endl;
  cout << "Date: " << day.month<< "/" << day.date  << "/" << day.year << endl;

}

/* Output :
Name of month: October
Date: 14
Month: 10
Year: 1996
*/
