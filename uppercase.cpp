//Joanitha Christle Gomez

#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;
void uppercaseCstring(char cstring[]);
void uppercaseCplusString(string &plusStr);

int main()
{
  string str = "Hello world 1234"; // C++ string
  char cstr[] = "Heyllo123" ; // C string

  uppercaseCstring(cstr);
  uppercaseCplusString(str);
  cout << "uppercaseCstring: " << str << endl << endl;
  cout << "uppercaseCplusString: " << cstr << endl << endl;
}

void uppercaseCstring(char cstring[])
{
  int index = 0;
  while (cstring[index] != '\0') // reading characters until null is reached
  {
    cstring[index] = toupper(cstring[index]); // changing each character to uppercase
    index++;
  }
}

void uppercaseCplusString(string &plusStr)
{
  for (int i = 0; i < plusStr.length(); i++)
  {
    plusStr[i] = toupper(plusStr[i]);// changing each character to uppercase
  }
}

/* OUTPUT :

uppercaseCstring: HELLO WORLD 1234

uppercaseCplusString: HEYLLO123
*/
