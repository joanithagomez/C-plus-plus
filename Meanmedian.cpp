#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int* readArray(const char* filename, int& size)
{
  int *array;

  ifstream file(filename);

  if (!file)
  {
    cout << "Error" ;
    exit(1);
  }

  string sizeLine, numberLine;
  int number;
  getline(file,sizeLine);
  size = atoi(sizeLine.c_str());
  array = new int[size];
  int i = 0;

  while (!file.eof()){
    getline(file,numberLine);
    number = atoi(numberLine.c_str());
    array[i] = number;
    i++;
  }
  file.close();
  return array;
}
//insertionSort Function
void insertionSort(int size,const int *data[]){
  int j;
  const int* value;

  //iterate through entire list
  for(int i = 1; i < size; i++){
     value = data[i];
     j = i - 1;

     while(j >= 0 && *data[j] > value){
               data[j + 1] = data[j];
               j = j - 1;
     }//end while
     data[j + 1] = value;

  }//end for
}


float median(int numElems,const int array[]){// function calculating median
  int median;
  const int *tempArray[50];
  for(int i = 0; i < numElems; i++)
  {
    tempArray[i] = &array[i];
  }
  insertionSort(numElems, tempArray);
  int mid = numElems / 2;
  if (numElems % 2 != 0){ // if num of elems is odd, median = (n/2)th element
    median = *tempArray[mid];
  }
  else{  // if num of elems is even, median = ((n/2) + 1)th + (n/2)th) /2)
    median = round((*tempArray[mid - 1] + *tempArray[mid]) /2.0);
  }
  return median;
}



int main(int argc, char* argv[]){
  if (argc != 2){
    cout << "Usage: ./a.out path\n";
    exit(1);
  }
  int size;
  int *numbers = readArray(argv[1], size);
  cout << "Median: " << median(size, numbers) << endl;
  return 0;
}
