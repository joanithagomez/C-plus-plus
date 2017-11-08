//Joanitha Christle Gomez
//Dec 6th, 2015
//Mac OSx ; g++
//Description: A to-do list program which allows to add and remove items from any position
//in the list
//Demonstrates classes, linked lists and templates

#include <iostream>
#include <fstream> // for ofstream
#include <cctype> // for isspace
#include "hw5ll.h"
#include "todo.h"
using namespace std;

//******************************************************************
// Definition of function openOutputFile.
// As parameter, it accepts ofstream object passed by reference to open
// outfile to write
// This function takes filename from the user and returns true if file
// is open and false otherwise.
//******************************************************************

bool openOutputFile(ofstream &ofs)
{
	string filename;// variable for name of the output file

	cout << "Enter the output filename: ";
	getline(cin, filename);				// getting name of output file from user
	if( isspace(filename[filename.length()-1]) )
			filename.pop_back();
	ofs.open(filename.c_str());		// if there is a space at the end, remove .
		filename.pop_back();
	return ofs.is_open();
}

//******************************************************************
// Definition of function getUsersChoice.
// Function displays menu and gets the choice from user.
//******************************************************************

char getUsersChoice()
{
  char choice; // to store user's choice
  //Display menu
  cout << "\n=========================================\n";
  cout << "\t*To Do List Menu*\n";
  cout << "  I: Insert a todo item.\n  R: Remove a todo item.\n  D: Display list.\n";
  cout <<  "  W: Write list to an output file.\n  Q: Quit program.\n";
  cout << "Enter your choice: ";
  cin >> choice;
  cout << endl;
  choice = toupper(choice);
  cin.ignore(); //ignore any newline from the stream.
  return choice;
}

//******************************************************************
// Definition of function insertItem.
// Function asks the user what to insert and position for
// where to insert. It then calls linkedList's insertNode function to
// insert item at the given position.
// Finally displays if insertion successful or not.
//******************************************************************
void insertItem(LinkedList<ToDoItem> &obj)
{
  string str1, str2; //strings to store task and location from the user
  int pos = 0; // to store postion for where to insert

  cout << "Enter the task to add:";
  getline(cin, str1);
  cout << "Enter the task location, or [Enter] if none: ";
  getline(cin, str2);
  cout << "Enter the position to insert: ";
  cin >> pos;
  while(pos < 0)
  {
    cout << "Invalid position. Try again: ";
    cin >> pos;
  }
  cin.ignore(); //ignore any newline from the stream

  //calling linkedList's function that inserts using a local ToDoItem
  ToDoItem todo(str1, str2);
  if(obj.insertNode(pos, todo))
    cout << "Inserted the new item successfully!\n";
  else
    cout <<"Unable to insert the item at position "<< pos << endl;
}

//******************************************************************
// Definition of function removeItem.
// Function gets position from user and calls linkedList's deleteNode
// function to remove the item at that postion.
// Displays if removal successful or not.
//******************************************************************

void removeItem(LinkedList<ToDoItem> &obj)
{
  int itemPos; //To store user's input
  cout << "Enter the position of item to remove:"; //asking user for position
  cin >> itemPos;
  cin.ignore(); //ignores the newline from the stream

  if(obj.deleteNode(itemPos))//calling  list's deleteNode function to delete at position 'itemPos'
    cout << "Item # "<< itemPos << " removed successfully!\n";
  else
    cout << "Unable to remove item at position #" << itemPos << endl;
}

//**************************************************************
// writeToFile function: uses the openOutputFile function ,
// and if it opens, calls the list's display function passing the
// ofstream.
//**************************************************************

void writeToFile(LinkedList<ToDoItem> &obj,ofstream& outFile)
{
  if(!openOutputFile(outFile)) //if not open, display error and exit program
  {
    cout << "Error opening file.";
    exit(0);
  }
  cout << "Writing to file ...\n";
  obj.displayList(outFile); //writing to output file
  outFile.close(); // closing output file
}


int main()
{
  ofstream outFile;
  char choice = getUsersChoice();
  LinkedList<ToDoItem> objlist;

  //Loop to repeat until the user enters 'Q'
  while(choice != 'Q')
  {
    // switch statement to call stand-alone functions
    switch(choice)
    {
      //if choice is I, call insertItem function
      case 'I':
        insertItem(objlist);
        break;
      //if choice is R, call removeItem function
      case 'R':
        removeItem(objlist);
        break;
      //if choice is D, call displayList function
      case 'D':
        objlist.displayList(cout);
        break;
      //if choice is W, call writeToFile function
      case 'W':
        writeToFile(objlist, outFile);
        break;
      //if choice is any other character, display choice is Invalid
      default:
        cout << "Invalid choice!\n";
        break;
    }
    choice = getUsersChoice();

  }
  cout << "Quitting program.\n\n";
  return 0;
  }
/***********************************
OUTPUT

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: I

Enter the task to add:Buy gas
Enter the task location, or [Enter] if none: the gas station
Enter the position to insert: 1
Inserted the new item successfully!

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: i

Enter the task to add:Walk the dog
Enter the task location, or [Enter] if none: the trail
Enter the position to insert: 1
Inserted the new item successfully!

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: I

Enter the task to add:Bathe the dog
Enter the task location, or [Enter] if none: home
Enter the position to insert: 2
Inserted the new item successfully!

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: D

Walk the dog at the trail
Bathe the dog at home
Buy gas at the gas station

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: I

Enter the task to add:Wash the car
Enter the task location, or [Enter] if none: the car wash
Enter the position to insert: 4
Inserted the new item successfully!

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: i

Enter the task to add:Get a haircut
Enter the task location, or [Enter] if none: the barber
Enter the position to insert: 4
Inserted the new item successfully!

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: d

Walk the dog at the trail
Bathe the dog at home
Buy gas at the gas station
Get a haircut at the barber
Wash the car at the car wash

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: R

Enter the position of item to remove:5
Item # 5 removed successfully!

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: d

Walk the dog at the trail
Bathe the dog at home
Buy gas at the gas station
Get a haircut at the barber

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: W

Enter the output filename: todo.txt
Writing to file ...

=========================================
	*To Do List Menu*
  I: Insert a todo item.
  R: Remove a todo item.
  D: Display list.
  W: Write list to an output file.
  Q: Quit program.
Enter your choice: Q

Quitting program.

Joanitas-Air:CIS jo$ g++ list1.cpp && ./a.out
***********************************************************/
