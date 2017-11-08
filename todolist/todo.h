#ifndef TODOITEM_H
#define TODOITEM_H
#include <iostream>
using namespace std;

class ToDoItem
{
private:
  string task; //string to hold the task
  string location; //string for the location
public:
   //Default constructor
  ToDoItem() : task(""), location("") {}
  ToDoItem(string t, string loc);

  //Accessors
  string getTask() const { return task; }
  string getLocation() const { return location; }

  //mutators
  void setTask(string tsk) { task = tsk; }
  void setLocation(string lctn) { location = lctn; }

//member function for operator < (compares tasks only)
  bool operator<(ToDoItem& rhs)
  { return (this->task < rhs.task); }
//member function for operator == (returns true if tasks are equal)
  bool operator==(ToDoItem &rhs)
  { return this->task == rhs.task; }
//member function for operator != (returns true if tasks are not equal)
  bool operator!=(ToDoItem& rhs)
  { return !(this->task == rhs.task); }

  friend ostream& operator<<(ostream& os, ToDoItem& rhs);
};

//**************************************************************
// Constructor with 2 string parameters, assigns to corresponding
// string member variables
//**************************************************************

ToDoItem::ToDoItem(string t, string loc){
  setTask(t);
  setLocation(loc);
}

//**************************************************************
// friend operator<< function for the ToDoItem class that writes
// the task string, but doesn't write the " at " or location
// string unless the location string isn't empty
//**************************************************************

ostream& operator<<(ostream& os, ToDoItem& rhs){
  os << rhs.task ;
  if(rhs.location != "")
    os << " at " << rhs.location;

  return os;
}

#endif
