/*
Name: Isha Mudgal
Lab 4- Finite state machine for expression a*b*ab
Class: CSCI 3080 Dr Pettey
Due: 5th december 2016
*/
#include <iostream>

using namespace std;

void buildLookUpTable(int [7][4]);

int main()
{   //necessary variables
	char input;
	int luTable[7][4];
	int curState = 0;

	buildLookUpTable(luTable); //build array
	
	for(int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		cout << luTable[i][j];
	cout << endl;
	}

	/*while (cin.get(input))  //while input continues
	{   
		cout << luTable[curState][3]; //print output for current state
		//change state according to the input
		if (input == 'a')
			curState = luTable[curState][1]; 
		else if (input == 'b')
			curState = luTable[curState][2];
	}*/
	
	return 0;
}

//This function hard codes the look up table into the array
void buildLookUpTable(int luTable[7][4])
{
	//first column is the states
	for (int i = 0; i <= 7; i++)
	{
		luTable[i][0] = i;
	}
	//build look up table
	luTable[0][1] = 1; //second column is the state for input 'a'
	luTable[0][2] = 2; //third column is the state for input 'b'
	luTable[0][3] = 0; //fourth column is output

	luTable[1][1] = 1;
	luTable[1][2] = 3;
	luTable[1][3] = 0;

	luTable[2][1] = 4;
	luTable[2][2] = 2;
	luTable[2][3] = 0;

	luTable[3][1] = 4;
	luTable[3][2] = 2;
	luTable[3][3] = 1;

	luTable[4][1] = 6;
	luTable[4][2] = 5;
	luTable[4][3] = 0;

	luTable[5][1] = 6;
	luTable[5][2] = 6;
	luTable[5][3] = 1;

	luTable[6][1] = 6;
	luTable[6][2] = 6;
	luTable[6][3] = 0;

}