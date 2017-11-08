// Name: Joanitha Christle Gomez
// Program to practice using classes and structs
#include <iostream>
#include <fstream>  // for ifstream
#include <cctype>   // for tolower
#include <cstdlib>  // for atoi
#include <time.h>   //for srand
using namespace std;

enum GUESS_STATUS { NONLETTER, LOST, MISSED, REPEATGUESS, MATCHED, WON };

const int MAX_WRONG_GUESSES = 6;    //number of guesses allowed


struct Hangman
{
  const string* completeAnswer;
  string usersAnswer;
  string userGuessLetters;
  int wrongGuesses;
};


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

//private member functions
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
  getline(cin, filename);         //Get name of file and store in filename


  //If the last character of filename is space, it removes the
  //last character and reduces it's length by 1.
  if(isspace(filename[filename.length() - 1]))
		filename.pop_back();
  inputFile.open(filename.c_str()); //Opens file
  return inputFile.is_open();
}


WordDatabase::WordDatabase(ifstream &infile){
	strArray = 0;
	ptrStrArray = 0;
	numElems = currIndex = 0;
	readFile(infile);
}


void WordDatabase::readFile(ifstream &infile){
	if (!infile)
		return;
	if (numElems != 0){ // in case we're reading new strings
	 clearMemory();
	}
	freadStrArray(infile);
	initPtrStrArray();
	mixupPtrArray();
} // end readFile


//check if there are strings available
bool WordDatabase::hasMoreStrings() const{
  return (currIndex < numElems);
}


const string *WordDatabase::getNextString(){
	if (currIndex < numElems)
		return (ptrStrArray[currIndex++]);
  return 0; // if no more strings
}

//******************************************************************
// Parameters: ifstream object
// This function reads the file passed to it line by line, and creates an array of strings
// with the actual number of strings
//******************************************************************


void WordDatabase::freadStrArray(ifstream &infile){
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
//Definition of function initPtrStrArray
//Function creates a pointer to string array and assigns the address of
//string to each element
//******************************************************************

void WordDatabase::initPtrStrArray()
{
  //Dynamically allocating array of pointers to string
    ptrStrArray = new string*[numElems];

  //Loop to assign to each element of the array of pointers to strings the address of
  //the corresponding element in the array of strings
    for(int i = 0; i < numElems; i++) {
      ptrStrArray[i] = &strArray[i];
      strToLower(strArray[i]);
    }
} // end initPtrStrArray


//******************************************************************
//Definition of function stringToLower
//Function recieves a string passed by reference
//and changes string to all lowercase
//******************************************************************

void WordDatabase::strToLower(string &str)
{
	for (int i = 0; i < str.length(); ++i){
		str[i] = tolower(str[i]); // each string to lowercase
	}// end for
} // end strToLower



//******************************************************************
//  Definition : Function mixes up the array of pointers to strings by
//  getting a random index [0 to size - 1] for
//  each element and swapping the ith element of the array with the element
//  at random index.
//******************************************************************

void WordDatabase::mixupPtrArray()
{
  string* temp;               // To hold when swapping
  string **startptr;          // A local pointer for pointer traversal
  string **lastptr = ptrStrArray + numElems; // Another local pointer assigned after the last element
  int random;                 // Random number
  //Swap and mix up
  for(startptr = ptrStrArray; startptr < lastptr; startptr++){
       random = rand() % numElems;
       temp = *startptr;
       *startptr = ptrStrArray[random];
       ptrStrArray[random] = temp;
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

//******************************************************************
//Definition of function showInstructions
//Function displays game instruction
//******************************************************************

void showInstructions()
{
	cout << "Hangman Game\n";
  cout << "Try to guess which letters are in the word.\n";
  cout << "You have up to " << MAX_WRONG_GUESSES << " wrong guesses allowed.\n";
}

//******************************************************************
//Definition of function wantsToContinue
//Function asks if user wishes to continue playing
//******************************************************************
bool wantsToContinue(string &prompt)
{
	char Y_N;
	cout << prompt;
	cin >> Y_N;
	return toupper(Y_N) == 'Y';
} // end wantsToContinue

//******************************************************************
//Definition of function begin
//Function that resets all the values and starts game
//******************************************************************



bool begin(Hangman &hangman, WordDatabase *wordDB)
{
      hangman.completeAnswer = wordDB->getNextString();
      hangman.usersAnswer = "";
      //Initializing the struct's user's answer string to an underscore for
      //each character in the complete answer string
      for(int i = 0; i < hangman.completeAnswer->length(); ++i)
      {
        //initialize the struct's user's answer string to an underscore for
        //each character in the complete answer string
        hangman.usersAnswer.push_back('_');
      }
      hangman.userGuessLetters.clear();          //clearing the struct's guessed letter string
      hangman.wrongGuesses = 0;                  //intializing the number of wrong guesses to 0

    return true;

}
//******************************************************************
//Definition of function printWithSpaces
//Function to display string with space between characters
//******************************************************************


void printWithSpaces(string str){
  for(int i = 0; i < str.length(); i++) {
    cout <<str[i] << " ";
  }
  cout << endl;
}

//******************************************************************
//Definition of function updateUserAnswer
//Function to update users answer after each matching guess
//Function returns a bool
//******************************************************************


bool updateUserAnswer(Hangman &hangStruct, char guess){

  bool found = false;
  string ans = *hangStruct.completeAnswer;

  for (int i = 0; i < ans.length(); i++){
    if(guess == ans[i]){
      hangStruct.usersAnswer[i] = guess;
      found = true;
    }
  }

  return found;
}


enum GUESS_STATUS processGuess(char guess, Hangman &hangStruct)
{
	if (!isalpha(guess))  // if the guess is not a letter
		return NONLETTER;
	size_t pos; // check if already guesses
	pos = hangStruct.userGuessLetters.find(guess);
	if (pos != string::npos)
		return REPEATGUESS;

	hangStruct.userGuessLetters.push_back(guess);

	if (updateUserAnswer(hangStruct, guess)){// found in answer
		if (hangStruct.usersAnswer == *(hangStruct.completeAnswer))
			return WON;
		else
			return MATCHED;
	}
	else {
		++hangStruct.wrongGuesses; // incrementing wrong guess number
    if (hangStruct.wrongGuesses == MAX_WRONG_GUESSES)
      return LOST;

    cout << "Sorry, that's not in the word.";
    cout <<"\nYou have "<< MAX_WRONG_GUESSES - hangStruct.wrongGuesses << " more incorrect guesses allowed.\n";
    return MISSED;
	} // end else
} // end processGuess


enum GUESS_STATUS getGuess(Hangman &hangStruct)
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
      cout << "Invalid guess! ";
			cout << "Character MUST be a letter!\n";
			invalidInput = true;
		}
		else if (status == REPEATGUESS){
      cout << "Invalid guess! ";
			cout << "You already guessed that!\n";
			invalidInput = true;
		}// end ifelseo
	} while (invalidInput);

	return status;
} // end getGuess

//******************************************************************
//Definition of function play
//Function recieves status of the guess made and displays the
//corresponding message
//******************************************************************


void play(Hangman hangStruct){
    enum GUESS_STATUS status;
    do  // play the program until status reaches WON or LOST
    {
      printWithSpaces(hangStruct.usersAnswer);
      status = getGuess(hangStruct);

      if(status == MATCHED){
        cout << "You found a letter!\n";
      }
      else if(status == MISSED){
        cout << "Your guesses so far: " << hangStruct.userGuessLetters << endl;
      }
    }
    while(status != LOST && status != WON);

    if (status == LOST)
      cout << "Sorry, you used up all your chances.  The word is: " << *hangStruct.completeAnswer << endl;
    else
      cout << "CONGRATULATIONS! You got the word: " << *hangStruct.completeAnswer << endl;
}


int main()
{
  srand(time(NULL));        //Function for initializing the random function
  ifstream infile;          //File stream objects
  WordDatabase *wordDB;     //Instance of class
  Hangman hangman;          //struct object

  if(!openFile(infile))
  {
    //If file fails to open, display error message and exit program
    cout << "Error opening the file!" << endl;
    exit(0);
  }

  wordDB = new WordDatabase(infile);  //Assigning to WordDatabase* variable a NEW instance of a WordDatabase

  showInstructions();
  string prompt = "Continue? (Y/N): ";

  while(wantsToContinue(prompt) && wordDB->hasMoreStrings()){
    begin(hangman, wordDB);
    play(hangman);
  }


  //delete objects from memory
    delete wordDB;
    return 0;
}
/* OUTPUT
Joanitas-Air:CIS jo$ g++ hw.cpp && ./a.out
Enter filename: str.txt
Hangman Game
Try to guess which letters are in the word.
You have up to 6 wrong guesses allowed.
Continue? (Y/N): y
_ _ _ _ _ _

Enter a letter: a
Sorry, that's not in the word.
You have 5 more incorrect guesses allowed.
Your guesses so far: a
_ _ _ _ _ _

Enter a letter: t
You found a letter!
_ _ _ t _ _

Enter a letter: d
You found a letter!
_ _ _ t _ d

Enter a letter: s
Sorry, that's not in the word.
You have 4 more incorrect guesses allowed.
Your guesses so far: atds
_ _ _ t _ d

Enter a letter: x
Sorry, that's not in the word.
You have 3 more incorrect guesses allowed.
Your guesses so far: atdsx
_ _ _ t _ d

Enter a letter: m
You found a letter!
m _ _ t _ d

Enter a letter: a
Invalid guess! You already guessed that!

Enter a letter: e
You found a letter!
m e _ t e d

Enter a letter: l
CONGRATULATIONS! You got the word: melted

**************************************************************************/
/*USERLOSING
_ _ _ _ _ _ _

Enter a letter: a
You found a letter!
_ _ _ _ a _ _

Enter a letter: s
You found a letter!
_ _ s _ a _ _

Enter a letter: s
Invalid guess! You already guessed that!

Enter a letter: o
Sorry, that's not in the word.
You have 5 more incorrect guesses allowed.
Your guesses so far: aso
_ _ s _ a _ _

Enter a letter: i
You found a letter!
i _ s _ a _ _

Enter a letter: p
Sorry, that's not in the word.
You have 4 more incorrect guesses allowed.
Your guesses so far: asoip
i _ s _ a _ _

Enter a letter: q
Sorry, that's not in the word.
You have 3 more incorrect guesses allowed.
Your guesses so far: asoipq
i _ s _ a _ _

Enter a letter: l
Sorry, that's not in the word.
You have 2 more incorrect guesses allowed.
Your guesses so far: asoipql
i _ s _ a _ _

Enter a letter: w
Sorry, that's not in the word.
You have 1 more incorrect guesses allowed.
Your guesses so far: asoipqlw
i _ s _ a _ _

Enter a letter: k
Sorry, you used up all your chances.  The word is: instant
Continue? (Y/N): */
