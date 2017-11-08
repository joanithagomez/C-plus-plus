//Joanitha Christle Gomez
//Extra credit #1
//Driver's License Exam
//Mac OSx ; g++


#include <iostream>
using namespace std;
void getAnswers(char input[], char solnArray[]);
void evaluate(char input[], char solnArray[], int &score, int* wngAnsAry, int &index);
void display(char input[], char solnArray[], int scr, int *wAns, int wrongAnsSize);

const int MAX = 20;

int main()
{
  char solutionAry[MAX] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
  char inputAry[MAX];
  int *wrongAnsAry;
  int wrongAnsSize;
  wrongAnsAry = new int[wrongAnsSize];               //Array of incorrectly answered questions
  int score;

  getAnswers(inputAry, solutionAry);
  evaluate(inputAry, solutionAry, score, wrongAnsAry, wrongAnsSize);
  display(inputAry, solutionAry, score, wrongAnsAry, wrongAnsSize);

}

void getAnswers(char input[], char solnArray[])
{
  for (int i = 0; i < MAX; i++)
  {
    cout << "Answer " << i + 1 << ": " ;
    cin >> input[i];
    input[i] = toupper(input[i]);
    if (!isalpha(input[i]) || input[i] > 'D')
    {
      cout << "Invalid! Enter A, B, C or D.\n";
      i = i - 1;
    }

  }

}

void evaluate(char input[], char solnArray[], int &score, int *wngAnsAry, int &index)
{
  index  = 0;
  score= 0;
  for (int i = 0; i < MAX; i++)
  {

    if(input[i] == solnArray[i])
    {
      score++;
    }
    else
    {
      wngAnsAry[index] = i + 1;
      index++;

    }
  }
}

void display(char input[], char solnArray[], int score, int *wAns, int wsize)
{
  cout << "=================================================\n";
  cout << "\t\tDRIVER'S LICENSE EXAM\n";
  cout <<  "=================================================\n\n";

  if(score >= 15)
    cout << "Congratulations! You passed!\n";
  else
    cout << "Sorry! You failed.\n";

  cout << "Your score is: " << score << endl;

  cout << "Total number of correctly answered questions: " << score << endl;
  cout << "Total number of incorrectly answered questions: " << MAX - score << endl;
  cout << "Question numbers of incorrectly answered questions: ";
  for(int i = 0; i < wsize; i++)
  {
    cout  << wAns[i] ;
    if (i != wsize - 1)
    {
      cout << ", " ;
    }
  }
  cout << endl << endl;
  cout << "THANK YOU!\n";
  cout <<  "=================================================\n\n";

}
