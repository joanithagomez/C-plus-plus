//Joanitha Christle Gomez

#include <iostream>
#include <cctype>
using namespace std;
char *makeNewCString(char *oldString);


int main()
{

  char str[] = "Hi there!";
  cout << makeNewCString(str) << endl;

}

char *makeNewCString(char *oldString)
{
  int length = strlen(oldString);

  char *strArray = new char[length + 1];
  strArray = strncpy(strArray, oldString, length);
  return strArray;
}
