#include <iostream>
using namespace std;
int searchList(int list[], int numElems, int value);

int main()
{
  const int size = 4;
  int array[size] = {1,2,3,4};
  cout << "Position: " << searchList(array, size, 2) << endl;

}

int searchList(int *ary, int numElems, int value)
{
   int *startPtr = ary; // starting pointer at the first address of array
   int *lastPtr = startPtr + numElems - 1; // pointer at last address
   int position = -1;   // To record position of search value
   bool found = false; // Flag to indicate if value was found

   for (startPtr = ary; startPtr <= lastPtr && !found; startPtr++)
   {
      if (*startPtr == value) // If the value is found
      {
         found = true; // Set the flag
         position = startPtr - ary; // Record the value's subscript
      }
   }
return position; // Return the position, or -1
}
