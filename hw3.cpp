// Name: Joanitha Christle Gomez

#include <iostream>
#include <fstream>  // for ifstream
#include <cctype>   // for tolower
#include <cstdlib>  // for atoi
#include <time.h>   //for srand
using namespace std;

//Function prototypes
bool openFile(ifstream &inputFile);
string * read(ifstream &inFile, int &size);
void display(string *list , int size);
string** mixup(string** ptrArray, int size);
void displayPtrArray(string** ptrArray, int size);

const int WRONGMAX = 6;
struct Hangman
{
  string* answer;
  string usersAnswer;
  string guesses;
  int wrongGuesses;
}

class WordDatabase
{
private:
  string *strArray;  // will hold the array of strings
  string **ptrStrArray;// will hold the array of pointers to strings
  int numElems;  // how many elements used in the arrays
  int currIndex; // current index for the iterator

public:
  WordDatabase(){
    strArray = 0; ptrStrArray = 0;
    numElems = currIndex = 0; }
  WordDatabase(ifstream &infile);
  ~WordDatabase(){ clearMemory(); }

  void readFile(ifstream &infile);
  bool hasMoreStrings() const;
  const string *getNextString();

private:
  void clearMemory();
  void freadStrArray(ifstream &infile);
  void strToLower(string &str);
  void initPtrStrArray();
  void mixupPtrArray();
};


//******************************************************************
//Definition of function openFile.
//As paramter, it accepts ifstream object passed by reference to open
//file that contains size and string.
//This function takes filename from the user and returns true if file
//is open and false otherwise.
//******************************************************************

bool openFile(ifstream &inputFile)
{
  string filename;                //Define filename
  cout << "Enter filename: ";     //Asks user for name of file to be opened

  //Get name of file and store in filename
  getline(cin, filename);

  //If the last character of filename is space, it removes the
  //last character and reduces it's length by 1.
  if(isspace(filename[filename.length() - 1]))
		filename.pop_back();


  inputFile.open(filename.c_str()); //Opens file
  return inputFile.is_open();
}


WordDatabase::WordDatabase(ifstream &infile)
{
	strArray = 0;
	ptrStrArray = 0;
	numElems = currIndex = 0;
	readFile(infile);
}


//******************************************************************
// Definition of read function.
// Return type: String pointer
// Parameters: Size is passed by reference to modify the value of size in main
// program after obtaining the actual number of elements in the array.
// This function reads the file passed to it line by line, stores everthing except
// the first line in string array and then changes them to lowercase.
//******************************************************************


void WordDatabase::readFile(ifstream &infile)
{
	if (!infile)
		return;
	if (numElems != 0){ // in case we're reading new strings
	 clearMemory();
 }

	freadStrArray(infile);
	initPtrStrArray();
	mixupPtrArray();
} // end readFile


bool WordDatabase::hasMoreStrings() const{
	return (currIndex < numElems);
}

const string *WordDatabase::getNextString()
{
	if (currIndex < numElems)
		return (ptrStrArray[currIndex++]);
  return 0; // if no more strings
}

void WordDatabase::freadStrArray(ifstream &infile)
{
	int i;

	infile >> numElems;
	if (numElems <= 0){
		infile.close();
		return;
	}
	strArray = new string[numElems];
	for (i = 0; i < numElems && infile >> strArray[i]; ++i)
		; // do nothing else
	numElems = i; // assign actual size
	infile.close();
} // end freadStrArray



//******************************************************************
//Definition of function makePtrArray
//Function takes two parameters: array of strings and size of that array.
//This function makes an array of pointers to strings and assigns to each
//element the address of the corresponding element in the array of strings
//******************************************************************

void WordDatabase::initPtrStrArray()
{
  //Dynamically allocating an array of pointers to string
    ptrStrArray = new string*[numElems];

  //Loop to assign to each element of the array of pointers to strings the address of
  //the corresponding element in the array of strings
    for(int i = 0; i < numElems; i++)
    {
      ptrStrArray[i] = &strArray[i];
      strToLower(strArray[i]);
    }
} // end initPtrStrArray



//******************************************************************
//Definition of function display
//Parameters: Array of strings and it's size
//Function displays the contents of array of strings.
//******************************************************************
void display(string *list , int size)
{
  for (int i = 0; i < size; i++){
    cout << list[i] << endl;

  }
}

//******************************************************************
//Definition of function stringToLower
//Function recieves a string passed by reference
//and changes string to all lowercase
//******************************************************************

void WordDatabase::strToLower(string &str)
{
	for (int i = 0; i < str.length(); ++i){
		str[i] = tolower(str[i]);
	}// end for
} // end strToLower

//******************************************************************
// Definition of function reverseStrCopy
// Functions recieves a string and returns the
// reverse copy of it.
//******************************************************************


string reverseStrCopy(string cppstr){

	string reverse;                        //Reverse copy of the string passed
	int length = cppstr.length();          //length of string

	for(int i = length - 1; i >= 0; i-- ){
		reverse.push_back(cppstr[i]);

	}
	return reverse;
}

//******************************************************************
// Definition of function isPalindrome
// Function recieves a string and checks if the string is a palindrome.
// Returns true if it is a palindrome and false otherwise.
//******************************************************************


bool isPalindrome(string str)
{

    return (reverseStrCopy(str).compare(str) == 0);

}

//******************************************************************
// Definition of function displayPalindromes
// Function is passed array of pointers to strings and size of the array.
// It finds how many strings are palindromes and displays them using the
// array of pointers to strings. Also displays "not a palindrome" otherwise.
//******************************************************************

void displayPalindromes(string **str1, int size)
{
  int count;                // To count the number of palindromes
  string **startptr;                  // A local pointer for pointer traversal
  string **lastptr = str1 + size; // Another local pointer assigned  after the last element

  for(startptr = str1; startptr < lastptr; startptr++)
  {

    if (isPalindrome(**startptr))
    {
      cout << **startptr << " is a palindrome!" << endl;
      count++;
    }


  }
  // If count of palindromes is still 0, there are no palindromes in the array
  if (count == 0)
    cout << "There are no palindromes." << endl;

}
//******************************************************************
//Definition of function mixup
//Function recieves array of pointers to string and its size as parameters.
//It mixes up the array of pointers to strings by getting a random index [0 to size - 1]
//for each element and swapping the ith element of the array with the element
//at random index. Function then returns the mixed array of pointers.
//******************************************************************

string** mixup(string** ptrArray, int size)
{
  string* temp;               // To hold when swapping
  string **startptr;          // A local pointer for pointer traversal
  string **lastptr = ptrArray + size; // Another local pointer assigned after the last element
  int random;                 // Random number

  //Swap and mix up
  for(startptr = ptrArray; startptr < lastptr; startptr++)
  {
       random = rand() % size;
       temp = *startptr;
       *startptr = ptrArray[random];
       ptrArray[random] = temp;
  }

  return ptrArray;
}

void WordDatabase::mixupPtrArray()
{
   // YOU WRITE: similar to what you did in HW#2, except
   //    you will assign to the string ** member variable, NOT
   //    a parameter

}

//******************************************************************
//Definition of function displayPtrArray
//Function recieves an array of pointers to string and its size as parameters.
//It displays the mixed up array of pointers.
//******************************************************************

void displayPtrArray(string** ptrArray, int size)
{
    string** startptr;                         // A local pointer for pointer traversal
    string** lastptr = ptrArray + size;    // Another local pointer assigned after the last element

    for(startptr = ptrArray; startptr < lastptr; startptr++){
      cout << **startptr << endl;
    }

}

void WordDatabase::clearMemory()
{
	if (strArray != 0)
		delete[] strArray;
	if (ptrStrArray != 0)
		delete[] ptrStrArray;
	strArray = 0;
	ptrStrArray = 0;
	numElems = 0;
}

int main()
{

  srand(time(NULL));        //Function for initializing the random function
  ifstream infile;          //File stream object


    if(!openFile(infile))
    {
      //If file fails to open, display error message and exit program
      cout << "Error opening the file!" << endl;
      exit(0);
    }

      //Calls read function and assigns the returned array of strings to arrOfstr
      arrOfstr = read(infile, size);

      //Call to make array of pointers to strings
      array = makePtrArray(arrOfstr, size);

      //Call to display palindromes
      displayPalindromes(array, size);

      //Call to mix up array of pointers to string
      mixup(array, size);
      cout << "\nString array in order: " << endl;

      //Call to display the array of strings in order
      display(arrOfstr ,size);

      //Call to display array of strings in mixed order
      cout << "\nString array mixed up: " << endl;
      displayPtrArray(array, size);

    return 0;
}

enum GUESS_STATUS getGuess(HangmanInfo &hangStruct)
{
	char guess;
	enum GUESS_STATUS status;
	bool invalidInput;


	do {
		invalidInput = false;
		cout << "\nEnter a letter: ";
		cin >> guess;
		guess = tolower(guess);
		status = processGuess(guess, hangStruct);
		if (status == NONLETTER){
			cout << "Character MUST be a letter!\n";
			invalidInput = true;
		}
		else if (status == REPEATGUESS){
			cout << "You already guesses that!\n";
			invalidInput = true;
		}// end ifelse
	} while (invalidInput);

	return status;
} // end getGuess

enum GUESS_STATUS processGuess(char guess, HangmanInfo &hangStruct)
{
	if (!isalpha(guess))
		return NONLETTER;
	size_t pos; // check if already guesses
	pos = hangStruct.userGuessLetters.find(guess);
	if (pos != string::npos)
		return REPEATGUESS;
	hangStruct.userGuessLetters.push_back(guess);
	if (updateUserAnswer(hangStruct, guess)){// found in answer
		if (hangStruct.userAnswer == *(hangStruct.completeAnswer))
			return WON;
		else
			return MATCHED;
	}
	else {
		++hangStruct.numWrongGuesses;
		if (hangStruct.numWrongGuesses == MAX_WRONG_GUESSES)
			return LOST;
		return MISSED;
	} // end else

} // end processGuess
