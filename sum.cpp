#include <iostream>
using namespace std;
double calcSum ( double ary[], int arySize );
int main()
{
  double array[2] ={1.5, 1.4};
  cout << calcSum(array, 2);
}
double calcSum ( double *ary, int arySize )
  {
   double sum;

   sum = 0.0;
  double *startPtr;
  double *endPtr;

  startPtr = ary;
  endPtr = ary + arySize - 1;
  while (startPtr <= endPtr)
  {
    sum += *startPtr ;
    startPtr++;
  }


   return sum;
}
