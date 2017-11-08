#include <iostream>
using namespace std;

void updateUserAnswer(string answer, string &blankStr, char guess)
{
  for (int i = 0; i < answer.length(); i++)
  {
    if(guess == answer[i]){
        blankStr[i] = guess;
      }
  }

}

int main(){
string ans = "hello";
string blankStr = "_____";
cout << blankStr << endl;
updateUserAnswer(ans, blankStr, 'e');
cout << blankStr << endl;
updateUserAnswer(ans, blankStr, 'h');
cout << blankStr << endl;
updateUserAnswer(ans, blankStr, 'l');
cout << blankStr << endl;
updateUserAnswer(ans, blankStr, 'o');
cout << blankStr << endl;

return 0;
}
