//Joanitha Christle Gomez
//Nov 21, 2015
//Mac OSx ; g++
//Program to practice using classes, arrays of objects,inheritance and polymorphism.

#include <iostream>
#include "hw4.h"
#include <cctype>		// for isspace
#include <fstream>	// for ifstream and ofstream
#include <sstream>  // for isstream
using namespace std;
const int MAX = 20;	// max number of elements

//******************************************************************
//Definition of function openInputFile.
//As parameter, it accepts ifstream object passed by reference to open
//file that contains pets
//This function takes filename from the user and returns true if file
//is open and false otherwise.
//******************************************************************

bool openInputFile(ifstream &ifs)
{
	string filename;			// variable for name of the input file

	cout << "Enter the input filename: ";
	getline(cin, filename); // getting name of input file from user
	if( isspace(filename[filename.length()-1]) ) // if there is a space at the end, remove .
		filename.pop_back();

	ifs.open(filename.c_str());
	return ifs.is_open();
}

//******************************************************************
//Definition of function openOutputFile.
//As parameter, it accepts ofstream object passed by reference to open
//outfile to write to
//This function takes filename from the user and returns true if file
//is open and false otherwise.
//******************************************************************

bool openOutputFile(ofstream &ofs)
{
	string filename;// variable for name of the output file

	cout << "Enter the output filename: ";
	getline(cin, filename);				// getting name of output file from user
	if( isspace(filename[filename.length()-1]) )
			filename.pop_back();
	ofs.open(filename.c_str());		// if there is a space at the end, remove .
		filename.pop_back();
	return ofs.is_open();
}

//******************************************************************
//Definition of function split.
//As parameter, it accepts a string, delimitor character and number
// of tokens to look for.
//It returns the array of tokens(words) in that string
//******************************************************************

string* split(string str, char delim, int numWords)
{
	string* tokens = new string[numWords]; 		// dynamically allocated array to store each token(word)
	int i = 0;																// index of array
	istringstream line( str );
	  while(!line.eof() && i < numWords)			//false when last word is reached or i reach max number of words in the string
	  {
	    getline(line, tokens[i], delim);			//separate at the delimitor and store the word in tokens array
	    i++;
	  }
	return tokens;														// return the array
}

//*********************************************************************
// Definition of read function.
// Return type: none
// Parameters: number of elements is passed by reference to modify
// the value of size in main program after obtaining the actual number
// of elements in the array.
// This function reads the file passed to it line by line, and calls split
// to break name, month, day, year and isIndoor/numTricks . So that they
// can be passed to the dynamically allocated Cat/Dog objects.
//*********************************************************************

void readFile(ifstream &infile, Pet** ptrArr, int &numElems)
{
	if (!openInputFile(infile)){			// if not open, exit
		cout << "Error opening file.";
		exit(0);
	}

	string* words;									// to store each token from split function
	string line;										// read each line
  int index = 0 ;

while(!infile.eof() && index <= MAX){
		getline(infile,line);					// read line from file
		words = split(line, ' ', 6);	// separate the words in split() function and store in words array

		// since string is read from input file, convert date to int
		int day = atoi(words[3].c_str());
		int month = atoi(words[2].c_str());
		int year = atoi(words[4].c_str());
		int fifthArg = atoi(words[5].c_str());

		if(words[0] == "Cat")
				ptrArr[index] = new Cat(words[1], month, day, year, fifthArg );
		else
				ptrArr[index] = new Dog(words[1], month, day, year, fifthArg );

		index++;
		delete [] words;
	}
		numElems = index - 1;
}
//******************************************************************
// Definition of insertionSort function.
// Return type: none
// Parameters: number of elements is passed and array of pointers to Pet
// This function sorts the array first comparing names and then birthdate
//******************************************************************

void insertionSort(int size, Pet **data){
  int j;
  Pet *val;

  //iterate through entire list
  for(int i = 1; i < size; i++){
	 val = data[i];
	 j = i - 1;

	 while(j >= 0 && *data[j] > *val){
			   data[j + 1] = data[j];
			   j = j - 1;
	 }//end while
	 data[j + 1] = val;
  }//end for
}//end insertionSort Function

//******************************************************************
// Definition of function displayPets
// Function is passed array of pointers to Pet, size of the array and
// fstream object to be able to work with cout and ofstream.
// It displays all the Pet objects pointed to in the array and
// the return values of each Pet's age, and humanYears. It also calls
// each Pet's speak function.
//******************************************************************

void displayPets(Pet** ptrArray, int size, ostream &os){
    for(int i = 0; i < size; i++)
	{
		// writing/ displaying pointer array objects to file
		ptrArray[i]->write(os);
		os << ", Human years = " << ptrArray[i]->humanYears();
		os << ", age = " << ptrArray[i]->currentAge() ;
		os << ", says " ;
		ptrArray[i]->speak(os) ;
		os << endl;
	}
}

//******************************************************************
// Definition of function writeFile
// Function is passed array of pointers to Pet, size of the array and
// ofstream object to be able to work with ofstream.
// If the openput file is open, it writes all the Pet objects pointed
// to in the array, the return values of each Pet's age, and humanYears.
// It also calls writes each Pet's speak function.
//******************************************************************

void writeFile(Pet** ptrArray, int size, ofstream &outFile){
	if(!openOutputFile(outFile))
	{
		cout << "Error opening outFile. ";
		exit(0);
	}
	displayPets(ptrArray, size, outFile);	// calling displayPets with outFile passed
}


	int main()
{
	Pet* ptrArray[MAX]; // array of 20 pointers to Pet.
	ifstream infile;
	ofstream outFile;

	int numElems;				// actual number of elements in the input file
	//Calling read function
	readFile(infile, ptrArray, numElems);
	//Calling to sort the array
	insertionSort(numElems, ptrArray);
	//Writing array into output file
	writeFile(ptrArray, numElems, outFile);
	// calling passing cout
	displayPets(ptrArray, numElems, cout);

	return 0;
}

/*output
Dog Name = Barky, Birthdate = March 2, 2011, Number of tricks = 0 , Human years = 30, age = 4, says  Woof!
Cat Name = Catty, Birthdate = February 2, 2012, isIndoor: 0, Human years = 28, age = 3, says  Meow!
Cat Name = Cheshire, Birthdate = September 9, 2009, isIndoor: 0, Human years = 40, age = 6, says  Meow!
Cat Name = Cutie, Birthdate = May 4, 2013, isIndoor: 1, Human years = 24, age = 2, says  Meow!
Cat Name = Cutie, Birthdate = November 22, 2013, isIndoor: 0, Human years = 24, age = 2, says  Meow!
Dog Name = Doggy, Birthdate = July 6, 2004, Number of tricks = 5 , Human years = 79, age = 11, says  Woof!
Dog Name = Doggy, Birthdate = July 6, 2005, Number of tricks = 3 , Human years = 72, age = 10, says  Woof!
Cat Name = Jellicle, Birthdate = January 2, 2012, isIndoor: 1, Human years = 28, age = 3, says  Meow!
Cat Name = JennyAnyDots, Birthdate = February 3, 2013, isIndoor: 1, Human years = 24, age = 2, says  Meow!
Cat Name = Kitty, Birthdate = January 1, 2011, isIndoor: 1, Human years = 32, age = 4, says  Meow!
Dog Name = Lassie, Birthdate = April 3, 2001, Number of tricks = 15 , Human years = 100, age = 14, says  Woof!
Cat Name = Meowy, Birthdate = February 3, 2015, isIndoor: 1, Human years = 0, age = 0, says  Meow!
Dog Name = Puppy, Birthdate = August 7, 2014, Number of tricks = 4 , Human years = 9, age = 1, says  Woof!
Dog Name = Puppy, Birthdate = August 9, 2014, Number of tricks = 2 , Human years = 9, age = 1, says  Woof!
Cat Name = RumTumTugger, Birthdate = July 7, 2007, isIndoor: 0, Human years = 48, age = 8, says  Meow!
Dog Name = Runner, Birthdate = May 4, 2013, Number of tricks = 3 , Human years = 16, age = 2, says  Woof!
Cat Name = Tigger, Birthdate = August 8, 2008, isIndoor: 0, Human years = 44, age = 7, says  Meow!
Dog Name = Wimpy, Birthdate = April 4, 2014, Number of tricks = 4 , Human years = 9, age = 1, says  Woof!
Dog Name = Wolfy, Birthdate = March 2, 2011, Number of tricks = 4 , Human years = 30, age = 4, says  Woof!
Dog Name = Woofy, Birthdate = October 10, 2010, Number of tricks = 10 , Human years = 37, age = 5, says  Woof!
*/
