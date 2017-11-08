#include <iostream>
#include <cmath>
using namespace std;
int* Range(int start, int end, int step, int& size);
void display(int *array, int size);

//range(10)
// [ 0, 1,2... 9]
int* Range(int x, int& size){

  return Range(0, x , 1, size);
}
//10 --1
int* Range(int start, int end, int &size)
{

  return Range(start, end, 1, size);

}

int* Range(int start, int end, int step, int& size){
  int divident = end - start;
  int divisor = step;
  size = divident / divisor;

  if(divident % divisor != 0){
    size = size + 1;
  }

  int* array= new int[size];
  int count = 0;
  for(int i = start; i < end; i = i + step){
    array[count] = i;
    count++;
  }
  return array;

}

void display(int *array, int size){
   cout << "[";
   for(int i = 0; i < size; i++)
   {
     cout << array[i] ;
     if (i != (size - 1)){
       cout << ", ";

     }
   }
   cout << "]";
}

int main(){
  int* array;
  int number, size;

  cout << "Range(10) :";
  display(Range(10, size),size);
  cout << endl;

  cout << "Range(5,10) :";
  display(Range(5, 10,size),size);
  cout << endl;

  cout << "Range(2,10) :";
  display(Range(2, 10,size),size);
  cout << endl;

  cout << "Range(5,10,2) :";
  display(Range(5, 10,2,size),size);
  cout << endl;

  cout << "Range(5,15) :";
  display(Range(5, 15, 3,size),size);
  cout << endl;
}
