#include <iostream>
#include <fstream>
#include <cctype>
#include "ll.h"
#include "todo.h"
using namespace std;

//===================================================================
bool openOutputFile(ofstream &ofs)
{
	string filename;
	cout << "Enter the output filename: ";
	getline(cin, filename);
	if(isspace(filename[filename.length() - 1]) )
		filename.pop_back();
	ofs.open(filename.c_str());
	return ofs.is_open();
}

//======================================================================
char getUsersChoice()
{
  char choice;
  cout << "\n=========================================\n";
  cout << "\t*To Do List Menu*\n";
  cout << "  I: Insert a todo item.\n  R: Remove a todo item.\n  D: Display list.\n";
  cout <<  "  W: Write list to an output file.\n  Q: Quit program.\n";
  cout << "Enter your choice: ";
  cin >> choice;
  cout << endl;
  choice = toupper(choice);
  cin.ignore();
  return choice;
}


//===================================================================
void insertItem(LinkedList<ToDoItem> &obj)
{
  string str1, str2;
  int pos = 0;

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
  cin.ignore();
  ToDoItem todo(str1, str2);
  if(obj.insertNode(pos, todo))
    cout << "Inserted the new item successfully!\n";
  else
    cout <<"Unable to insert the item at position "<< pos << endl;
}
//======================================================================
void removeItem(LinkedList<ToDoItem> &obj)
{
  int itemPos;
  //asking user for position
  cout << "Enter the position of item to remove:";
  cin >> itemPos;
  cin.ignore();
  // then calling  list's deleteNode function
  if(obj.deleteNode(itemPos))
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
  if(!openOutputFile(outFile))
  {
    cout << "Error opening file.";
    exit(0);
  }
  cout << "Writing to file ...\n";
  obj.displayList(outFile);
}

class ToDoList
{
private:
   LinkedList<ToDoItem> variable;
 public:
   void insertNode(string str1, string str2);
   void remove(string strRemv);
   void remove(int pos);
   void write(ostream& os)
   { os << variable; }

/*   member functions to add an item (2 string parameters), remove and item (1 string
   parameter OR 1 int parameter), and write the list to an ostream & (ostream &
   parameter).*/
}
int main()
{
  ofstream outFile;
  char choice = getUsersChoice();
  ToDoList objlist;

  while(choice != 'Q')
  {
    switch(choice)
    {
      case 'I':
        insertItem(objlist);
        break;
      case 'R':
        removeItem(objlist);
        break;
      case 'D':
        objlist.displayList(cout);
        break;
      case 'W':
        writeToFile(objlist, outFile);
        break;
      default:
        cout << "Invalid choice!\n";
        break;
    }
    choice = getUsersChoice();

  }
  cout << "Quitting program.\n\n";
  return 0;
  }
