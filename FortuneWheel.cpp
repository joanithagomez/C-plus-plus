//Fortune Wheel game
//Joanitha Christle Gomez
//8 October 2015
//Mac OSx ; g++
//DEscription: Plays wheel of fortune game by spinning wheel and adding the wheel values to total.
//If the wheel lands on 0, total is set to 0. A maximum of 10 spins are allowed.
//Finally  total is displayed.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

bool openFile(ifstream &inputFile);
int fileReadArray(int wheelAry[], ifstream &inFile);
void displayWheel(int array[], int numElems);
void playWheel(int numElems, int wheelAry[], int pickedAry[]);
bool wantsToRepeat();
void checkLastElem(int pickedAry[], int wheelAry[], int index);


const int WHEEL_SIZE = 30; // max size for wheel array
const int PICKED_SIZE = 10;// max number of picks

int main()
{
  int wheel[WHEEL_SIZE];
  int picked[PICKED_SIZE];
  ifstream inFile;

  openFile(inFile);

  int numElems = fileReadArray(wheel, inFile);
  inFile.close();

  displayWheel(wheel, numElems);
  playWheel(numElems, wheel, picked);
  checkLastElem(picked, wheel, numElems - 1);
}


bool openFile(ifstream &inputFile) // Opens file that contains wheel numbers
{
  string filename;
  cout << "Enter filename: ";
  getline(cin, filename);

  if(isspace(filename[filename.length() - 1]))
		filename.pop_back();

  inputFile.open(filename.c_str());
  return inputFile.is_open();
}



int fileReadArray(int wheelAry[], ifstream &inFile) //read numbers from file into wheel array
{
  string line;
  int index = 0;
  int number;
  while(!inFile.eof() && index < WHEEL_SIZE)
  {
    getline(inFile,line);
    number = atoi(line.c_str());
    wheelAry[index] = number;
    index++;
  }
  return index - 1;
}



void displayWheel(int array[], int numElems) //displays wheel array
{

  cout << "Wheel array: [";
  for(int i = 0; i < numElems; i++)
  {
    cout <<array[i] << (i == numElems - 1 ? "" : " ");
  }

cout << "]" << endl;
}



void playWheel(int numElems, int wheelAry[], int pickedAry[])
  {

  int pickedIndex = 0; // picked array index initialized to 0
  int total = 0; // total set to 0
  srand(time(0));

  do
  {
    int randomIndex = rand() % (numElems - 1);

    cout << "The wheel is spinning....... It landed on ";
    if (wheelAry[randomIndex] > 0)
    {
      cout << wheelAry[randomIndex] << endl;
      total += wheelAry[randomIndex];
    }
    else
    {
      total = 0;
      cout << "Bankrupt." << endl;
    }

    pickedAry[pickedIndex] = randomIndex;
    pickedIndex++;
    cout << "Your total now is " << total << endl;

  } while (pickedIndex < PICKED_SIZE && wantsToRepeat()); // close do while

  if (pickedIndex >= PICKED_SIZE)
  {
    cout << "No more spins allowed (only " << PICKED_SIZE << " allowed)" << endl;
  }
}


bool wantsToRepeat()
{
  char answer = 'n';

  cout << "Do you want to continue? (y for yes): ";
  cin >> answer;
  return (answer == 'y' || answer == 'Y');
}


void insertionSort(int data[], int numElems)
{
  int j, val;
  for(int i = 1; i < numElems; i++)      //iterate through entire list
  {
     val = data[i];
     j = i - 1;

     while(j >= 0 && data[j] > val)
     {
       data[j + 1] = data[j];
       j = j - 1;
     }
                                    //end while
     data[j + 1] = val;
  }                                 //end for
}



int binarySearch(const int array[], int numElems, int value)
{
  int first = 0,            // first array element
      last = numElems - 1,  // Last array elment
      middle,               // Midpoint of search
      position = -1;        // Position of search value
  bool found = false;       // Flag

  while (!found && first <= last)
    {
      middle = (first + last) / 2;

      if (array[middle] == value)
      {
        found = true;
        position = middle;
      }
      else if( array[middle] > value)
      {
        last = middle - 1;
      }
      else
      {
        first = middle + 1;
      }
    }                // while close
    return position;
}


void checkLastElem(int pickedAry[], int wheelAry[], int index)
{
  insertionSort(pickedAry, PICKED_SIZE);

  if (binarySearch(pickedAry, PICKED_SIZE, index) > -1)
    cout << "You got the last wheel value: "<< wheelAry[index]<< " in one or more of your spins!" << endl;
  else
    {
    cout << "You never got the last wheel value: " << wheelAry[index] << " in any of your spins!" << endl;
    }
}
/* OUTPUT
Joanitas-Air:CIS jo$ g++ FortuneWheel.cpp
Joanitas-Air:CIS jo$ ./a.out
Enter filename: PROGHW.txt
Wheel array: [7500 1250 3000 2750 9250 4000 8500 3750 1000 0 6500 1750 3500 8250 2500 9000 4750 5500 3250 0 5250 6750 7000 5000 2000 4500 9750 8000]
The wheel is spinning....... It landed on 3000
Your total now is 3000
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 5250
Your total now is 8250
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 2750
Your total now is 11000
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 7500
Your total now is 18500
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 8250
Your total now is 26750
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 1000
Your total now is 27750
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 3750
Your total now is 31500
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 7000
Your total now is 38500
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 1250
Your total now is 39750
Do you want to continue? (y for yes): y
The wheel is spinning....... It landed on 4000
Your total now is 43750
No more spins allowed (only 10 allowed)
You never got the last wheel value: 8000 in any of your spins!
*/
