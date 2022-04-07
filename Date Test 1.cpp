/********************************************************************************
*																				*
*	Program:	Date Test 1.cpp													*
*																				*
*	Author:		Michael Davis													*
*																				*
*	Date:		Nov 11, 2019													*
*																				*
*	Purpose:	This program will test the constructors, the inspectors, and	*
*				the mutators													*
*																				*
********************************************************************************/

#include <iostream>
#include "date.h"

using namespace std;

/********************************************************************************
*																				*
*	Function:	main															*
*																				*
********************************************************************************/

int main()
{
	//	Test the constructors

	cout << "Test the constructors" << endl;
	Date day_zero;
	Date xmas("Dec", 25, 2019);

	//	Test the inspectors

	cout << endl << "Test the inspectors" << endl << endl;
	cout << "The default date is " << day_zero.month() << ' ' << day_zero.day() << ", " << day_zero.year() << endl;
	cout << "Christmas is on " << xmas.month() << ' ' << xmas.day() << ", " << xmas.year() << endl;

	//	Test the mutators

	cout << endl << "Test the mutators" << endl << endl;
	xmas.month("Jul");
	xmas.day(4);
	xmas.year(1776);
	cout << "The Declaration of Independence was signed on " << xmas.month() << ' ' << xmas.day() << ", " << xmas.year() << endl;

	//	All doen

	cout << "Good-bye" << endl;

	system("pause");
	return 0;
}