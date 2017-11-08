#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

const int MAX_ELEMS = 50;

int fileReadArray(int intArray[],
				int maxElems);
void doCalculations(double &average,
			int &median,
			int intArray[],
			int numElems);
double calcAverage(const int intArray[],
			int numElems);
int calcMedian(const int intArray[],
			int numElems);
void insertionSortArray(int data[],
			int size);
void printOutput(double average,
			int median);

int main()
{
	int intArray[MAX_ELEMS];
	int numElems;
	double average;
	int median;

	numElems = fileReadArray(intArray, MAX_ELEMS);
	if( numElems <= 0 ){
		cout<<"Error opening the file or no numbers in the file\n";
		return 1;
	} //end if
	doCalculations(average, median, intArray, numElems);
	printOutput(average, median);
	return 0;
}// end main

int fileReadArray(int intArray[],
				int maxElems)
{
	ifstream inputFile;
	int index;

//should declare as const
inputFile.open("numbers.txt");
	if(!inputFile.is_open()) // or if( inputFile.fail())
		return -1;

	for(index=0;
  index<maxElems && inputFile>>intArray[index];
++index)
{
// empty loop
} // end for
inputFile.close();
return index;
} // end fileReadArray

void doCalculations(double &average,
			int &median,
			int intArray[],
			int numElems)
{
	average = calcAverage(intArray, numElems);
	median = calcMedian(intArray, numElems);
} // end doCalculations

double calcAverage(const int intArray[],
			int numElems)
{
	double sum=0.;

	for(int i=0; i < numElems; ++i)
		sum += intArray[i];
	// check numElems just in case
	if( numElems > 0)
		return sum/numElems;
	else
		return 0.;
} // end calcAverage

int calcMedian(const int intArray[],
			int numElems)
{
	int median;
	int tempArray[MAX_ELEMS];


	for( int i=0; i < numElems; ++i )
		tempArray[i] = intArray[i];
	insertionSortArray(tempArray, numElems);
	median = tempArray[numElems/2];
	if( numElems % 2 == 0)
		median = round((tempArray[numElems/2]+tempArray[numElems/2-1])/2.);
	return median;
} // end calcMedian


void insertionSortArray(int data[],
			int size)
{
  int j, val;

  //iterate through entire list
  for(int i = 1; i < size; i++){
	 val = data[i];
	 j = i - 1;

	 while(j >= 0 && data[j] > val){
			   data[j + 1] = data[j];
			   j = j - 1;
	 }//end while
	 data[j + 1] = val;
  }//end for

} // end insertionSortArray

void printOutput(double average,
			int median)
{
	cout<<"The average = "<< average << endl;
	cout<<"The median= "<<median<<endl;
} // end printOutput
