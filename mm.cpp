#include <iostream>

using namespace std;

const MAX = 5;
struct ArrayInfo
{
  string array[MAX];
  int numElems;
};

class Person
{
private:
  string name;
  ArrayInfo* phone;
  ArrayInfo* email;
public:
  Person();
  ~Person();
  void setName(string &nm);


};

Person::Person()
{
  phone = new ArrayInfo;
  email = new ArrayInfo;
  phone->numElems = 0;
  email->numElems = 0;

}

Person::~Person()
{
  delete phone;
  delete email;
}

void Person::setName(string &nm)
{
  name = nm;
}

bool Person::addPhone(string &newPhone)
{
  if( phones->numElems < MAX ){
			phones->strArray[phones->numStrs]= newPhone;
			++(phones->numStrs);
			return true;
		} // end if
		return false;
	} // end addPhone

}
