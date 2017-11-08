#include <iostream>
using namespace std;
class NumberQueue:// public NumberList// ANSWER TO B. IS FOR HERE
{
private:
	ListNode * tail;// ANSWER TO B. IS FOR HERE
public:
  NumberQueue():NumberList {tail = nullptr; }
  virtual void appendNode(double);
  virtual void insertNode(double);
  virtual double deleteNode(void);

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

int main()
{
  NumberQueue nm;
}
