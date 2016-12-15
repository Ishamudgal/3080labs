//Name: Isha Mudgal
//CSCI 3080 Fall 2016 Lab assignment #2
//Due: November 16, 2016
//This program inputs row/col and an array and sorts the array with respect to coloumn

#include <iostream>

using namespace std;

//to find the row that has the minimum column value
int minimumRow(int array[10][10], int sCol, int rows, int row1);

int main()
{   
	//variables to manipulate the array
	//row1 is a variable to store start row
	int row, col, sCol, row1,minRow;
	int array[10][10];


	//Input and display the original array
	cout << "Input the rows and columns: ";
	cin >> row >> col;

	cout << "Input the matrix: " << endl;
    
   for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> array[i][j];
		} 
	}

   cout << "Input Matrix:" << endl;

   for (int i = 0; i < row; i++)
   {
	   for (int j = 0; j < col; j++)
	   {
		   cout << array[i][j] << " ";
	   } cout << endl;
   }

   //input sort column
   cout << "Input the sort column: " << endl;
   cin >> sCol;
   
   //row1 is just a manipulator
   //decrement scol to fit c++ array syntax
   row1 = 0;
   sCol = sCol - 1;

   int temp;  //temporary variable to swap the rows

      while (row1 < row)
	{
		//find row that has the mininum value using function
		minRow = minimumRow(array, sCol, row, row1); //initialize with first minimum row

		//swap minimum value row with present row
		for (int j = 0; j < col; j++)
		{
			temp = array[row1][j];
			
			array[row1][j] = array[minRow][j];
			array[minRow][j] = temp;
		}

		//move to the next row
		row1++;
	}

     cout << "The sorted matrix is:" << endl;
   //display the sorted array
   for (int i = 0; i < row; i++)
   {
	   for (int j = 0; j < col; j++)
	   {
		   cout << array[i][j] << " ";
	   } cout << endl;
   }

	return 0;
}

int minimumRow(int array[10][10], int sCol, int row, int row1)
{
	//begin at present row and loop through the remaining rows
	int min = array[row1][sCol];
	int minRow = row1;  //start row

	for (row1; row1 < row; row1++)
	{
		//change minimum value and row number if a smaller number is found
		if (min > array[row1][sCol])
		{
			min = array[row1][sCol];
			minRow = row1;          
		}
	} //row1 is the minimum row at the end of this loop

	//return minimum row number
	return minRow;

}