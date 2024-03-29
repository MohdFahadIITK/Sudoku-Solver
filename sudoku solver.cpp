#include <bits/stdc++.h>
#define X 9
using namespace std;
int grid[X][X];/*={
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {4, 5, 6, 7, 8, 9, 1, 2, 3},
    {7, 8, 9, 1, 2, 3, 4, 5, 6},
    {2, 3, 4, 5, 6, 7, 8, 9, 1},
    {5, 6, 7, 8, 9, 1, 2, 3, 4},
    {8, 9, 1, 2, 3, 4, 5, 6, 7},
    {3, 4, 5, 6, 7, 8, 9, 1, 2},
    {6, 7, 8, 9, 1, 2, 3, 4, 5},
    {9, 1, 2, 3, 4, 5, 6, 0, 8}
 };*/
   

bool PresentInBox(int boxStartRow, int boxStartCol, int num){
//checking whether num is present in 3x3 box or not
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}

bool PresentInCol(int col, int num){ //checking whether num is present in col or not
   for (int row = 0; row < X; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool PresentInRow(int row, int num){ //checking whether num is present in row or not
   for (int col = 0; col < X; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}


void sudokuGrid(){ //To print the sudoku grid after solve
   for (int row = 0; row < X; row++){
      for (int col = 0; col < X; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<X; i++)
            cout << "---";
      }
      cout << endl;
   }
}

bool ValidPlace(int row, int col, int num){
   //when item not found in col, row and current 3x3 box
   return !PresentInRow(row, num) && !PresentInCol(col, num) && !PresentInBox(row - row%3 ,
col - col%3, num);
}

bool findEmptyPlace(int &row, int &col){ //To know empty location and update row and column
   for (row = 0; row < X; row++)
      for (col = 0; col < X; col++)
         if (grid[row][col] == 0) //If 0 then it is empty
            return true;
   return false;
}

bool solveSudoku(){
   int row, col;
   if (!findEmptyPlace(row, col))
      return true; //if  all places are filled then return 1
   for (int num = 1; num <= 9; num++){ // For valid numbers only 1 - 9
      if (ValidPlace(row, col, num)){ //checking validation, if yes, put the number in the grid
         grid[row][col] = num;
         if (solveSudoku()) //recursively go for other rooms in the grid
            return true;
         grid[row][col] = 0; //turning to unassigned space when conditions are not satisfied
      }
   }
   return false;
}
int main(){
   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
         cin>>grid[i][j];
      }
   }
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}
