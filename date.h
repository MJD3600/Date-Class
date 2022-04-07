/****************************************************************************
*																			*
*	File:		date.h														*
*																			*
*	Author:		Michael Davis												*
*																			*
*	Date:		Nov. 11, 2019												*
*																			*
*	Purpose:	This file contains the Date class definition				*
*																			*
****************************************************************************/

#ifndef DATE_H
#define DATE_H

//	Header files

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//	Month type

enum Month {JAN, FEB, MAR, APR,
	MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

/****************************************************************************
*																			*
*	Definition of the Date class											*
*																			*
****************************************************************************/

class Date
{
//	Public member functions

	public:

	//	Constructors

		Date();								// Default constructor
//		Date(const Date& date);				// Copy constructor
		Date(string m, int d, int y);		// Constructor

	//	Inspectors

		string month() const;				// Month inspector
		int day() const;					// Day inspector
		int year() const;					// Year inspector

	//	Mutators

		void month(string m);				// Month mutator
		void day(int d);					// Day mutator
		void year(int y);					// Year mutator

	//	Facilitators

		void input(istream& in);			// Read a date
		void output(ostream& out) const;	// Print a date
		Date add(int n) const;				// Add days to date
		bool isEqual(const Date& d) const;	// Compare dates
		bool isBefore(const Date& d) const;	// Compare dates

		
	//	Operators
	
		Date& operator++();					// Pre-increment to next date
		Date operator++(int);				// Post-increment to next date
		Date& operator--();					// Pre-decrement to prev date
		Date operator--(int);				// Post-decrement to prev date
		operator int() const;				// Convert date to integer

	//	Other member functions
	
		string weekday() const;				// Get day of the week
		static Date current();				// Get the current date
		bool isValid() const;				// Check whether a date is valid

//	Private member functions
	
	private:
	
		Date(int d);						// Convert integer to date
		Date(Month m, int d, int y);		// Construct a date
		static bool isLeapYear(int y);		// True if year is leap year
		static int daysInMonth(Month m, int y);	// Number of days in month
		
//	Private data members

    private:

		Month m_month;			// The month
		int m_day;				// The day
		int m_year;				// The year
};

/****************************************************************************
*																			*
*	Prototypes of operators													*
*																			*
****************************************************************************/

//	Input and output operators

istream& operator>>(istream& in, Date& date);
ostream& operator<<(ostream& out, const Date& date);

//	Date arithmetic operators

Date operator+(const Date& d, const int n);			// Add days to date
Date operator-(const Date& d, const int n);			// Subtract days from date
int operator-(const Date& d1, const Date& d2);		// Days between dates

//	Date comparison operators

bool operator==(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);
bool operator<(const Date& d1, const Date& d2);		// Earlier than
bool operator>(const Date& d1, const Date& d2);		// Later than
bool operator<=(const Date& d1, const Date& d2);
bool operator>=(const Date& d1, const Date& d2);

#endif