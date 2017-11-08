// Name: Joanitha Christle Gomez
// Program to practice using dynamically allocated arrays and check for palindromes

#include <iostream>
#include <fstream>  // for ifstream
#include <cctype>   // for tolower
#include <cstdlib>  // for atoi
#include <time.h>   //for srand
using namespace std;

//Function prototypes
bool openFile(ifstream &inputFile);
string * read(ifstream &inFile, int &size);
void stringToLower(string &str);
void display(string *list , int size);
string** makePtrArray(string* array, const int &size);
string reverseStrCopy(string cppstr);
bool isPalindrome(string str);
void displayPalindromes(string **str1, int size);
string** mixup(string** ptrArray, int size);
void displayPtrArray(string** ptrArray, int size);

int main()
{
  //Declaring an array of strings
  string* arrOfstr;

  //declaring an array of pointers to string
  string** array;

  int size;                 //Array size
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

      // Deallocating dynamically allocated memory
      delete [] array;
      delete [] arrOfstr;

    return 0;
}

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


//******************************************************************
// Definition of read function.
// Return type: String pointer
// Parameters: Size is passed by reference to modify the value of size in main
// program after obtaining the actual number of elements in the array.
// This function reads the file passed to it line by line, stores everthing except
// the first line in string array and then changes them to lowercase.
//******************************************************************

string* read(ifstream &inFile, int &size)
{

    string sizeLine;                  // The first line of file that says how many strings are in the file
    getline(inFile,sizeLine);         // Gets first line from file and stores in sizeLine
    size = atoi(sizeLine.c_str());    // Since sizeLine is string, covert string value to integer and store in size

    string* array = new string[size]; //Dynamically allocated array to read and store strings


    //Index variable to loop, read and store strings in each element of the array
    int i = 0;

    while(!inFile.eof() && i < size)
    {
       getline(inFile,array[i]);

       if (array[i].empty())          //If an empty string is found, skip the element
          continue;

       stringToLower(array[i]);       //Call to convert each character to lowercase
       i++;
    }

    size = i;                         // Size of array is set to number of strings actually read from the file

    return array;

}

//******************************************************************
//Definition of function makePtrArray
//Function takes two parameters: array of strings and size of that array.
//This function makes an array of pointers to strings and assigns to each
//element the address of the corresponding element in the array of strings
//******************************************************************

string** makePtrArray(string* array, const int &size)
{

  //Dynamically allocating an array of pointers to string
  string** ptrArray = new string*[size];

  //Loop to assign to each element of the array of pointers to strings the address of
  //the corresponding element in the array of strings
    for(int i = 0; i < size; i++)
    {
      ptrArray[i] = &array[i];
    }

  return ptrArray;
}

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

void stringToLower(string &str)
{
  for (int i = 0; i < str.length(); i++)
  {
    str[i] = tolower(str[i]);           //Converting to lowercase one character at a time
  }

}

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

/*OUTPUT:
*****************************************************************
deed is a palindrome!
peep is a palindrome!
radar is a palindrome!


String array in order:
attempt
autumn
border
canal
coach
damage
deed
doll
facing
film
finest
garage
habit
hunter
instant
kick
label
melted
memory
mission
monkey
mount
nuts
palace
peep
poetry
radar
pride
rhyme
rocky
rubber
rush
sale
slope
soap
solar
species
vapor
wealth
wolf

String array mixed up:
mount
film
rocky
species
border
monkey
habit
kick
garage
finest
attempt
deed
hunter
instant
rubber
peep
wealth
wolf
canal
slope
label
pride
vapor
poetry
nuts
facing
soap
palace
solar
damage
doll
mission
autumn
melted
rush
sale
memory
radar
coach
rhyme
******************************************************************
*/
