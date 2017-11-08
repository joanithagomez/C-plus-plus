#include <iostream>
#include "Triangle.h"
#include <cstdlib>
#include <ctime>

using namespace std;
void assignTriangles(Triangle triArray[], int numElems);
void insertionSort(Triangle* triAry[], int numElems);

const int MAX_ELEMS = 10;

int main()
{
	Triangle triArray[MAX_ELEMS];
	Triangle *ptrArray[MAX_ELEMS];

	srand(time(0));
	assignTriangles(triArray, MAX_ELEMS);


	for( int i=0; i < MAX_ELEMS; ++i )
	{
			ptrArray[i] = &triArray[i];
  }


	insertionSort(ptrArray, MAX_ELEMS);
	for( int i=0; i < MAX_ELEMS; ++i )
	{
			cout << *ptrArray[i] <<  ", area= " << ptrArray[i]->area() << ", perim= " << ptrArray[i]->perimeter() << endl;
	}
}

void pickValidSides(double &a, double &b, double &c) {
	a = rand()%(45 - 21 + 1) + 21;
	b = rand()%(45 - 21 + 1) + 21;
	c = rand()%(45 - 21 + 1) + 21;

	if(a + b > c && a + c > b && b + c > a) {
		return;
	} else {
		pickValidSides(a, b, c);
	}
}

void assignTriangles(Triangle triArray[], int numElems)
{

    double a, b, c;
    for(int i=0; i < numElems; ++i)
    {
				a = rand()%(45 - 21 + 1) + 21;
				b = rand()%(45 - 21 + 1) + 21;
				c = rand()%(45 - 21 + 1) + 21;

        triArray[i].setSideA(a);
        triArray[i].setSideB(b);
        triArray[i].setSideC(c);
    }
}

void insertionSort(Triangle* triAry[], int numElems)
{
  int j;
	Triangle* val;
  for(int i = 1; i < numElems; i++)      //iterate through entire list
  {
     val = triAry[i];
     j = i - 1;

     while(j >= 0 && *triAry[j] > *val)
     {
       triAry[j + 1] = triAry[j];
       j = j - 1;
     }
                                    //end while
     triAry[j + 1] = val;
  }
}                              //end for
