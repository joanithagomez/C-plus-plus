#include <iostream>
using namespace std;
const int COL = 3;
void printMatrix(int matrix[][COL], int numRows);

void transpose(int matrix[][COL], int numRows) {

  for(int row = 0; row < numRows; row++)
  {
    for(int col = row; col < COL;  col++)
    {
      swap(matrix[row][col],matrix[col][row]);
    }
  }
  printMatrix(matrix, numRows);
}

void printMatrix(int matrix[][COL], int numRows) {
  for(int i = 0; i < numRows; i++) {
    for(int j = 0; j < COL; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
};

int main() {
  int matrix[][COL] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  transpose(matrix, 3);
}
