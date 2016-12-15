//Name: Isha Mudgal
//CSCI/MATH 3080 Fall 2016 Lab assignment #1
//due November 9, 2016
//PART 1: This program main will call a recursive function S to determine the value for the nth term.

#include <iostream>

using namespace std;

int S(int n);   //Function declaration for recursive function S

int main()
{
	int nTerm;  //variable to store user input;
	
	cout << "This program determines the nth term for the sequence S(n-1) + n" << endl;
	cout << "Enter a value for n: ";
	cin >> nTerm;

	cout << "The nth term is: " << S(nTerm);  //call function and print result
		
	return 0;
}

int S(int n)    //Function definition for recursive function S
{
	if (n == 1)    //First term is 1
		return 1;
	else
	return S(n - 1) + n;  //calls itself until nth term is reached
}