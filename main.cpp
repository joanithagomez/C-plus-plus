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

/* output
Joanitas-Air:CIS jo$ g++ Triangle.cpp main.cpp
Joanitas-Air:CIS jo$ ./a.out
1st side=41, 2nd side=27, 3rd side=21, area= 253.085, perim= 89
1st side=32, 2nd side=30, 3rd side=21, area= 304.868, perim= 83
1st side=23, 2nd side=31, 3rd side=31, area= 331.062, perim= 85
1st side=23, 2nd side=39, 3rd side=31, area= 356.416, perim= 93
1st side=44, 2nd side=35, 3rd side=21, area= 361.248, perim= 100
1st side=22, 2nd side=36, 3rd side=36, area= 377.061, perim= 94
1st side=30, 2nd side=26, 3rd side=39, area= 389.758, perim= 95
1st side=38, 2nd side=37, 3rd side=26, area= 456.931, perim= 101
1st side=31, 2nd side=33, 3rd side=35, area= 468.074, perim= 99
1st side=40, 2nd side=36, 3rd side=42, area= 662.051, perim= 118
Joanitas-Air:CIS jo$

*/
