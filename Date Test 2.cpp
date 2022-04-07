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
	//	Test the output operator

	cout << "Construct some dates" << endl;
	Date independence("Jul", 4, 1776);
	Date christmas("Dec", 25, 2019);
	Date today = Date::current();
	cout << "Independence Day was " << independence.weekday() << ", " << independence << endl;
	cout << "Christmas will be " << christmas.weekday() << ", " << christmas << endl;
	cout << "Today is " << today.weekday() << ", " << today << endl;

	//	Test the input operator

	cout << endl << "Test the input operator" << endl << endl;
	cout << "Enter your birthday: ";
	Date birthday;
	cin >> birthday;
	cout << "You were born on " << birthday.weekday() << ", " << birthday << endl;

	//	Test the equality operators

	cout << endl << "Test the equality operators" << endl << endl;
	if (christmas == Date("Dec", 25, 2019))
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;

	if (christmas != independence)
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;

	//	Test the relational operators

	cout << endl << "Test the relational operators" << endl << endl;
	if (independence < christmas)
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;

	if (christmas > independence)
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;

	if (independence <= christmas)
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;
	
	if (christmas >= independence)
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;

	//	Test the arithmetic operators

	cout << endl << "Test the arithmetic operators" << endl << endl;
	cout << "10 days from today will be " << today + 10 << endl;
	cout << "10 days ago was " << today - 10 << endl;
	cout << "Christmas is " << christmas - today << " days away" << endl;

	//	Test the increment operator

	cout << endl << "Test the increment operator" << endl << endl;
	cout << "The 12 days of Christmas:" << endl;
	for (Date d = christmas; d < christmas + 12; d++)
		cout << d << endl;

	//	Test the isValid function

	cout << endl << "Test the isValid function" << endl << endl;
	Date good_day("Feb", 29, 2020);
	Date bad_day("Feb", 29, 2019);

	if (good_day.isValid())
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;

	if (bad_day.isValid())
		cout << "incorrect" << endl;
	else
		cout << "correct" << endl;

	//	All done

	cout << "Good-bye" << endl;

	system("pause");
	return 0;
}