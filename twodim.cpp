#include <iostream>
using namespace std;

const int COL_SIZE = 50;

void columnAvg(float avgArray[], float twoDArray[][COL_SIZE],int numRows, int numCols)
{
  for(int col = 0; col < numCols; col++)
  {
    float total = 0;

    for(int row = 0; row < numRows; row++)
    {
      total += twoDArray[row][col];
    }
    avgArray[col] = total/numRows;
  }

}

int main()
{
  int rows = 5;
  int columns = 3;
  float arrOfAverage[COL_SIZE];
  float twoDimArr[][COL_SIZE] = {{1,2.5,3.3},{4.5,3.4,5.0},{1.1,3,22.4}, {30,10,20}, {4,22,10.3}};
  columnAvg(arrOfAverage,twoDimArr,rows,columns);

  for(int i = 0; i < columns; i++)
  {
    cout << arrOfAverage[i] << " ";
  }
  cout << endl;
  return 0;
}
