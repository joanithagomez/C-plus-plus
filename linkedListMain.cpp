#include "Date.h" //or put the whole class here
#include "Linkedlist.h" // or put the whole class here

// stand-alone "client" operator!= function:
bool operator!=( Date&left, const Date &right)

{
     return !(left == right);
}

int main()
{
    LinkedList<Date> dateList;

    int month, day, year;

    for(int count = 0; count < 3; ++count)
    {
        cout <<"Enter a date:  MM DD YYYY: ";
        cin >> month >> day >> year;
        Date date(month, day, year);
        dateList.insertNode(date);
    }
    cout << "The list has: \n";
    dateList.displayList(cout);

    Date tempDate(1,1,1900);
    dateList.insertNode(tempDate);
    cout << "\nNow the list has: \n";
    dateList.displayList(cout);

    Date deletedate(1,1,1900);
    if(dateList.deleteNode(deletedate))
    {
      cout << deletedate << " successfully deleted!\n";
    }
    else
      cout << "Unable to delete.\n";

    cout << "The list has: \n";
    dateList.displayList(cout);

    return 0;
}
