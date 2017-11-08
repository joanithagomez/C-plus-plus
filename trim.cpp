#include <iostream>
#include <string>
using namespace std;
string trimRight(string str);
string trimLeft(string str2);
string padRight(string str3,int n);
string padLeft(string str4, int n);


string trimRight(string str){
  int length = str.length();

  while (str[length - 1] == ' '){
    str.pop_back();
    length--;
  }

  return str;
}

string trimLeft(string str2){

    while(str2[0] == ' '){
      str2.erase (0, 1);
    }

  return str2;
}


string padRight(string str3,int n){

  while (str3.length() < n){
      str3.push_back(' ');
    }

  return str3;
}

string padLeft(string str4, int n)
{
  while(str4.length() < n){
    str4.insert(0, " ");

  }
  return str4;
}


int main()
{
//  cout << "Trim left: " << trimRight(trimLeft("    Hello    ")) << endl;
  cout << "Padright:" << padRight("small", 4).compare("small") << endl;
  cout << "Padright:" << padRight("small", 7).compare("small  ") << endl;

  cout << "Padleft:" << padLeft("small", 4).compare("small")  << endl;
  cout << "Padleft:" << padLeft("small", 7).compare("  small")  << endl;

}
