#define NUMBERLIST_H
#include <iostream>
using namespace std;

class NumberList
{
protected:
   struct ListNode
   {
      double value;           // The value in this node
      struct ListNode *next;  // To point to the next node
   };
   ListNode *head;            // List head pointer

public:
   NumberList(){ head = NULL; }
   ~NumberList() {};
   // Linked list operations
   virtual void appendNode(double num) {
     ListNode *newNode;  // To point to a new node
     ListNode *nodePtr;  // To move through the list

     // Allocate a new node and store num there.
     newNode = new ListNode;
     newNode->value = num;
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
   }
   virtual void insertNode(double num) {
     ListNode *newNode;					// A new node
     ListNode *nodePtr;					// To traverse the list
     ListNode *previousNode = nullptr;	// The previous node

     // Allocate a new node and store num there.
     newNode = new ListNode;
     newNode->value = num;

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

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
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

   virtual void displayList() const {
     ListNode *nodePtr;  // To move through the list

     // Position nodePtr at the head of the list.
     nodePtr = head;

     // While nodePtr points to a node, traverse
     // the list.
     while (nodePtr)
     {
        // Display the value in this node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
     }
   }

   virtual int numberOfNodes(void) const
   {
     ListNode* temp;
     int count = 0;
     while(temp != NULL)
     {
       temp = temp->next;
       count++;
     }
     return count;
   }
};

class NumberQueue: public NumberList// public NumberList// ANSWER TO B. IS FOR HERE
{
private:
	ListNode * tail;// ANSWER TO B. IS FOR HERE
public:
  NumberQueue():NumberList(){tail = NULL; }

  virtual void appendNode(double newValue)
  {
    ListNode* newNode = new ListNode;
    newNode->value = newValue;
    newNode->next = NULL;

    if(!head)
    {
      head = newNode;
      tail = newNode;
      newNode->next = NULL;
      return;
    }

    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
  }

  virtual void insertNode(double newvalue)
  {
    appendNode(newvalue);
  }

  virtual double deleteNode()
  {
    double value = head->value;
    ListNode* nextNode ;
    nextNode = head->next ;
    delete head;
    head = nextNode;
    return value;
  }

   void mysteryFunction(){ // ANSWER TO C. IS FOR HERE
	  ListNode *nodePtr, *prevPtr;
	  if( head != NULL ){
        	nodePtr = head;
	  	prevPtr = NULL;
        	while (nodePtr != tail){
			prevPtr = nodePtr;
      			nodePtr = nodePtr->next;
   	  	} // end while
	  	if( prevPtr != NULL ){
			prevPtr->next = NULL;
			tail->next = head;
			head = tail;
			tail = prevPtr;
		} // end if prevPtr != NULL
	  }// end if head!=NULL
    } // end mysteryFunction
};

class Stock
{
private:
    string symbol;		// Trading symbol of the stock
     NumberQueue sharePrices;   // Current price per share
public:
    Stock(){ symbol="";}
    Stock(string sym){ symbol=sym; }
    void setSymbol(string sym){ symbol = sym; }
    void addPrice(double newPrice)
    {
      sharePrices.appendNode(newPrice);
	  }
    string getSymbol() const{ return symbol; }
    double removeOldestSharePrice()
    { return sharePrices.deleteNode(); }
    void displayStockPrices() const {
      sharePrices.displayList();
    }
};

int main()
{
  Stock stk;
  stk.addPrice(3.3);
  stk.addPrice(3.22);
  stk.displayStockPrices();
  stk.removeOldestSharePrice();
  stk.displayStockPrices();

/*  NumberQueue nm;
  nm.appendNode(1.0);
  nm.appendNode(2.0);
  nm.appendNode(3.0);

  nm.displayList();
*/
}
