#include <iostream>
using namespace std;

struct IntArray
{
	int* intArray;
	int arrSize;
};

struct IntPtrArray
{
	int **intPtrArray;
	int arrSize;
};


void makeIntPtrArray(IntPtrArray &intPArray, const IntArray &iArray)
 {
	 intPArray.arrSize = iArray.arrSize;
	 intPArray.intPtrArray = new int*[intPArray.arrSize];
	 for(int i = 0; i < intPArray.arrSize; i++)
	 {
		 intPArray.intPtrArray[i] = &iArray.intArray[i];
	 }

 }
