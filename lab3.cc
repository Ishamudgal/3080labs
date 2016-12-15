//Name: Isha Mudgal
//CSCI 3080 Fall 2016 Lab assignment #3
//Due: November 28, 2016
//This program reads in the number of nodes and a binary relation representing a graph. 
//Then creates an adjacency matrix from the binary relation and finds isolated nodes, adjacent nodes, possibility of euler path
//and degree of node.

#include <iostream>

using namespace std;

int main()
{
	int nodes, row, col, option, node, count = 0, count1 = 0;
	int array[10][10];
	char ch;
	
	//user input- number of nodes
	cout << "Enter number of nodes: ";
	cin >> nodes;
	cout << endl;

	//initialize the array to zero
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			array[i][j] = 0;
		}
	}

	//input the binary relation
	cout << "Enter the binary relation: ";
	cin >> ch;

	while (ch != '}')     //continue until end of input
	{
		if (ch == '(')          //if character at the current position is an open parenthesis
		{
			cin >> row >> ch >> col;   //row is the integer at next position
			                           //column number is the integer three places from '('
			array[row - 1][col - 1] = 1;     //subtract 1 from row and column to follow c++ array syntax
			                                 //insert 1 at the position
		}
		cin >> ch;
	}
	cout << endl;
    //Print menu	
	cout << "1. Print the adjacency matrix " << endl;
	cout << "2. Determine if there are any isolated nodes " << endl;
	cout << "3. Determine the degree of a node " << endl;
	cout << "4. Determine if an Euler path exists " << endl;
	cout << "5. Determine if one node is adjacent to another " << endl;
	cout << "6. Quit \n" << endl;
	cout << "Choose option: ";          //user input
	cin >> option;
   //continue while user chooses to exit	
	while (option != 6)
	{
		switch (option)
		{
		//traverse through array and PRINT it
		case 1: cout << " Array is " << endl;
			for (int i = 0; i < nodes; i++)
			{      cout<< " " ;
				for (int j = 0; j < nodes; j++)
					cout << array[i][j] << " ";
				cout << endl;
			}
			break;
		//ISOLATED NODES
	    //traverse through array, while adding the values in every row
		case 2: for (int i = 0; i < nodes; i++)
		{
			row = 0;
			for (int j = 0; j < nodes; j++)
			{
				row += array[i][j];
			}
			if (row == 0)        //if sum of values is zero then it is not connected to any other node
				cout <<" "<< i + 1 << " is and isolated node." << endl;
		}
				break;
        //DEGREE of node
		//traverse through the columns of row same as node value while counting non zero values
		case 3: cout << " Insert node: ";
			cin >> node;

			for (int i = node - 1, j = 0;j < nodes;j++)
			{
				if (array[i][j] == 1)
					count++;
			}
			cout << " Degree of node " << node << " is " << count << endl; //degree of node is the count
			break;
        //EULER PATH
		case 4: count = 0;
			for (int i = 0; i < nodes; i++)
			{
				for (int j = 0; j < nodes; j++)
				{
					if (array[i][j] == 1) //count degrees
						count++;
				}
			}
			if (count % 2 != 0)   //if degrees are odd then increment count1
			{
				count1++;
			}

			if (count1 == 0 || count1 == 2) //if number of odd degrees is 0 or 2 euler path exists
			{
				cout << " Euler path exists." << endl;
			}

			else
				cout << " Euler path does not exist" << endl;

			break;
        //ADJACENT NODES
		case 5: cout << " Enter node 1: ";
			int node2;            //input nodes for comparison
			cin >> node;
			cout << " Enter node 2: ";
			cin >> node2;
			//if the value at the array position of both nodes as row and column is not 0 then nodes are adjacent
			if (array[node - 1][node2 - 1] != 0)
				cout << " Node " << node << " and " << node2 << " are adjacent." << endl;
			else
				cout << " Node " << node << " and " << node2 << " are not adjacent." << endl;
			break;
       }
	cout << "Choose option: ";
	cin >> option;
	}
	
	cout << "Goodbye." << endl;
	return 0;
}