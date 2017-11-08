
#include <iostream>
using namespace std;
template <class T>
  struct Node
  {
    T data;
    T next;
  };

template <class T>
class List
{
private:

  T head;
  int itemCount;

public:
  List()
  { head = nullptr; itemCount = 0; }
  bool isEmpty()
  {
    return(head == nullptr);
  }

  int getitemCount()
  { return itemCount; }
  void appendNode(T newValue);
  void insertAt(int position, T newValue);
  void deleteAt(int position);
  void displayList(ostream& os);
  T makeNode(T newValue);
};

template <class T>
T List<T>::makeNode(T newValue)
{
  //making a new node
T newNode = new T;
  newNode->data = newValue;
  newNode->next = nullptr;
  return newNode;
}
template <class T>
void List<T>::appendNode(T newValue)
{
  //making a new node
  T newNode = makeNode(newValue);

  if(isEmpty())
  {
    head = newNode;
  }
  else
  {
    T last;
    T temp = head;
    while(temp->next != nullptr)
    {
      temp = temp->next;
    }
    last = temp;
    last->next = newNode;
  }
  itemCount++;
}


template <class T>
void List<T>::insertAt(int position, T newValue)
{
  T oldhead = nullptr;
  T last = nullptr;
  T currnext = nullptr;
  //making a new node
  T newNode = makeNode(newValue);

  int index = 1;
  T temp = head;
  if(position > itemCount)
    return;

  if(position == 1) {
    oldhead = head;
    head = newNode;
    head->next = oldhead;
    itemCount++;
    return;
  }


  while(temp->next != nullptr)
  {
    if(index == position - 1)
      break;

    temp = temp->next;
    index++;
  }
  currnext = temp->next;
  temp->next = newNode;
  newNode->next = currnext;
  itemCount++;
}

template <class T>
void List<T>::deleteAt(int position)
{
  T temp;
  T temp1;

  T nextNode;
  int index = 1;
  if(position > itemCount)
    return;

  if(position == 1)
  {
    temp = head->next;
    delete head;
    head = temp;
    itemCount--;
  }
  else
  {
    temp = head;
    while(temp->next != nullptr)
    {
      if(index == position - 1)
        break;

      temp = temp->next;
      index++;
    }

    //temp "one" one->nextnode = hello
    nextNode = temp->next; // two "hello"
    temp->next = nextNode->next;  //three
    delete nextNode;

    itemCount--;
  }
}

template <class T>
void List<T>::displayList(ostream& os)
{
   T nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      os << nodePtr->data << endl;
      // Move to the next node.
      nodePtr = nodePtr->next;
   }
 }
int main()
{
  List<string> objlist ;
  List<Node*> ;
/*  objlist.appendNode("Hello!");
  objlist.appendNode("world");
  objlist.insertAt(2, "two");
  objlist.insertAt(1, "one");
  objlist.insertAt(3, "three");
  objlist.insertAt(objlist.getitemCount() , "foo");

  objlist.displayList(cout);
  cout << endl;

  // Delete the middle node.
  cout << "Now deleting the  second node.\n";
  objlist.deleteAt(2);

  // Display the list.
  cout << "Here are the nodes left.\n";
  objlist.displayList(cout);
  cout << endl;

  cout << "Now deleting the third node.\n";
  objlist.deleteAt(3);
  cout << "Here are the nodes left.\n";
  objlist.displayList(cout);
  cout << endl;


  // Delete the only node left in the list.
  cout << "Now deleting the only remaining node.\n";
  objlist.deleteAt(1);
  cout << "Now deleting the  second node.\n";
  objlist.deleteAt(2);

  // Display the list.
  cout << "Here are the nodes left.\n";
  objlist.displayList(cout);
  cout << endl;
  cout << "Now deleting the only remaining node.\n";
  objlist.deleteAt(1);

  // Display the list.
  cout << "Here are the nodes left.\n";

  objlist.displayList(cout);
  cout << endl;
  cout << "itemCount: "<< objlist.getitemCount();
  cout << endl;
  cout << "IsEmpty: " << objlist.isEmpty();
  cout << endl;
*/
  return 0;
}
