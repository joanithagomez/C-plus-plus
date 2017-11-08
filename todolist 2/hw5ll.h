
#include <iostream>     // For cout
using namespace std;

template <class T>
class LinkedList
{
private:

    int itemCount;  // count how many are in the list

    // Declare a structure for the list
    struct ListNode*
    {
       T value;                // The value in this node
       struct ListNode *next;  // To point to the next node
    };

   ListNode *head;   // List head pointer

public:
   // Constructor
   LinkedList()
      { head = nullptr; itemCount = 0; }

   // Destructor
   ~LinkedList();

   // Linked list operations
   void appendNode(T);
   void insertNode(T);
   void deleteNode(T);
   void displayList(ostream& os) const;
   bool insertNode(int position, T newValue);
   bool deleteNode(int position);
   int& operator[](int& subscript)
   {
     if(subscript < 0 || subscript >= itemCount)
     {
      cout << "Error";
     }
     return ListNode[subscript];
  }


};


//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
   ListNode *newNode;  // To point to a new node
   ListNode *nodePtr;  // To move through the list

   // Allocate a new node and store newValue there.
   newNode = new ListNode;
   newNode->value = newValue;
   newNode->next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end.
   {
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find the last node in the list.
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node.
      nodePtr->next = newNode;
   }
   itemCount++;
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

template <class T>
void LinkedList<T>::displayList(ostream& os) const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      os << nodePtr->value << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }

}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
   itemCount++;

   ListNode *newNode;					// A new node
   ListNode *nodePtr;					// To traverse the list
   ListNode *previousNode = nullptr;	// The previous node

   // Allocate a new node and store newValue there.
   newNode = new ListNode;
   newNode->value = newValue;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to nullptr.
      previousNode = nullptr;

      // Skip all nodes whose value is less than newValue.
      while (nodePtr != nullptr && nodePtr->value < newValue)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}
//**************************************************
// This insertNode function inserts a node with
// newValue at a particular position
//*************************************************

template <class T>
bool LinkedList<T>::insertNode(int position, T newValue)
{
  ListNode * oldhead = NULL;
  ListNode * last = NULL;
  ListNode * currnext = NULL;
  ListNode * temp; //	// To traverse the list

  // Allocate a new node and store newValue there.
  ListNode * newNode = new ListNode;
  newNode->value = newValue;
  newNode->next = NULL;

  int index = 1; // index of the node where "temp" is
  temp = head; // Position temp at the head of list.

  /* if position of the item to be inserted is greater
  than number of items in the list, return false */
  if(position > itemCount + 1)
    return false;

  // if the first node is the one, insert at the head
  if(position == 1) {
    oldhead = head;
    head = newNode;
    head->next = oldhead;
    itemCount++; //if successfully inserted, increment itemCount
    return true;
  }
  else
  {

    // Skip nodes until position is reached,
    // and break from loop to insert at that position
    while(temp->next != NULL)
    {
      if(index == position - 1)
        break;

      temp = temp->next;
      index++;
    }
    currnext = temp->next;
    temp->next = newNode;
    newNode->next = currnext;
    itemCount++; // if successful, increment itemCount
    return true;
  }
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return ;

   // Determine if the first node is the one.
   if (head->value == searchValue)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
      itemCount--;// if successfully deleted, decrement itemCount
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->value != searchValue)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
         itemCount--; // if successfully deleted, decrement itemCount
      }
   }

}

//*****************************************************
// This deleteNode function deletes the node at a given position
// Returns true if removed and false otherwise.
//*****************************************************

template <class T>
bool LinkedList<T>::deleteNode(int position)
{
  ListNode * temp;   // To traverse the list
  ListNode * deletePosition; // To store the node at delete position
  int index = 1;       // index of the node where "temp" is

  // If the list is empty, do nothing.
  if (!head)
     return false;

//if position of the item to be deleted is greater than number of items
//return false
  if(position > itemCount)
    return false;

// Determine if the first node is the one.
  if(position == 1)
  {
    temp = head->next;
    delete head;
    head = temp;
    itemCount--;  //if successfully deleted, decrement itemCount
    return true;
  }
  else{
    // Initialize temp to head of list
    temp = head;

    while(temp->next != NULL){
    //when temp is pointing at the item before the item to be deleted break from loop
      if(index == position - 1)
        break;
      temp = temp->next;
      index++;
    }

    //store what temp is pointing at. (i.e the node to be deleted)
    deletePosition = temp->next;
    temp->next = deletePosition->next;  //Link temp to the item deletePosition node was linked to
    delete deletePosition;  // Now delete deletePosition node

    itemCount--; // if successfully deleted, decrement itemCount
    return true;
  }
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
int main()
{
   // Define a NumberList object.
   LinkedList listObject;

   cout << listObject[2];
   cout << "Number of nodes: ";
   cout << list.numberOfNodes();
   // Build the list with some values.
   list.appendNode(2.5);
   list.appendNode(7.9);
   list.appendNode(12.6);

   // Display the list.
   cout << "Here are the initial values:\n";
   list.displayList();
   cout << endl;

   return 0;
}
