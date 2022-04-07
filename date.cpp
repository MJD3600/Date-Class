/****************************************************************************
*																			*
*	File:		date.cpp													*
*																			*
*	Author:		Michael Davis												*
*																			*
*	Date:		Nov. 11, 2019												*
*																			*
*	Abstract:	This file contains the implementations of the Date			*
*				class member functions and operators						*
*																			*
****************************************************************************/

//	Header files

#include <iostream>
#include <string>
#include <cassert>
#include "date.h"

using namespace std;

/****************************************************************************
*																			*
*	Function:	Date()														*
*																			*
*	Purpose:	To create a Date object										*
*																			*
*	Note:		This is the default constructor								*
*																			*
****************************************************************************/

Date::Date()
{
	m_month = JAN;
	day(1);			// Creates a default date to use where ever is needed
	year(1601);
}

/****************************************************************************
*																			*
*	Function:	Date(string, int, int)										*
*																			*
*	Purpose:	To create a Date object for a given month, day, and year	*
*																			*
****************************************************************************/

Date::Date(string m, int d, int y)
{
	month(m);
	day(d);		// sets the certain date to the ones set by the user if the month is a string 
	year(y);
}

/****************************************************************************
*																			*
*	Function:	Date(Month, int, int)										*
*																			*
*	Purpose:	To create a Date object for a given month, day, and year	*
*																			*
****************************************************************************/

Date::Date(Month m, int d, int y)
{
	assert(m >= JAN && m <= DEC);
	m_month = m;					// This sets the certain date to the ones set by the user if using the ENUM type for the month
	day(d);
	year(y);
}

/****************************************************************************
*																			*
*	Function:	Date(int)													*
*																			*
*	Purpose:	To a date from an integer which represents the number of	*
*				days since Jan 1, 1601 into a date							*
*																			*	
****************************************************************************/

Date::Date(int d)
{
	//	Establish the number of days in various time periods

	const int DAYS_IN_1_YEAR = 365;
	const int DAYS_IN_4_YEARS = 4 * DAYS_IN_1_YEAR + 1;
	const int DAYS_IN_100_YEARS = 25 * DAYS_IN_4_YEARS - 1;
	const int DAYS_IN_400_YEARS = 4 * DAYS_IN_100_YEARS + 1;

	//	Handle the days in groups of 400 years

	int y = 1601 + 400 * (d / DAYS_IN_400_YEARS);	// Add mult of 400 years
	d %= DAYS_IN_400_YEARS;						// Get remaining days

												//	Handle the remaining days in groups of 100 years

	int n = d / DAYS_IN_100_YEARS;				// Number of centuries
	if (n == 4)									// Adjust for extra day in 
		n = 3;									// 4th century
	y += 100 * n;								// Add mult of 100 years
	d -= n * DAYS_IN_100_YEARS;					// Get remaining days

												//	Handle the remaining days in groups of 4 years

	y += 4 * (d / DAYS_IN_4_YEARS);				// Add mult of 4 years
	d %= DAYS_IN_4_YEARS;						// Get remaining days

												//	Handle the remaining days in groups of 1 year

	n = d / DAYS_IN_1_YEAR;						// Number of years
	if (n == 4)									// Adjust for extra day in
		n = 3;									//   4th year
	y += n;										// Add years
	d -= n * DAYS_IN_1_YEAR;					// Get remaining days

												//	Use a for loop to find the month and day in the month

	d++;
	Month m;
	for (m = JAN; m < DEC && d > daysInMonth(m, y); m = (Month)(m + 1))
		d -= daysInMonth(m, y);

	//	Initialize the date

	m_month = m;
	m_day = d;
	m_year = y;
	return;
}

/****************************************************************************
*																			*
*	Function:	month														*
*																			*
*	Purpose:	To return the month of the date								*
*																			*
****************************************************************************/

string Date::month() const
{
	switch (m_month)
	{
	case JAN: return "Jan"; break;
	case FEB: return "Feb"; break;
	case MAR: return "Mar"; break;		// If this function is called it swaps back the ENUM type that was set back to the orginal string 
	case APR: return "Apr"; break;
	case MAY: return "May"; break;
	case JUN: return "Jun"; break;
	case JUL: return "Jul"; break;
	case AUG: return "Aug"; break;
	case SEP: return "Sep"; break;
	case OCT: return "Oct"; break;
	case NOV: return "Nov"; break;
	case DEC: return "Dec"; break;
	}
}

/****************************************************************************
*																			*
*	Function:	day															*
*																			*
*	Purpose:	To return the day of the date								*
*																			*
****************************************************************************/

int Date::day() const
{
	return m_day;
}

/****************************************************************************
*																			*
*	Function:	getYear														*
*																			*
*	Purpose:	To return the year of the date								*
*																			*
****************************************************************************/

int Date::year() const
{
	return m_year;
}

/****************************************************************************
*																			*
*	Function:	month														*
*																			*
*	Purpose:	To set the month of the date to a specified month			*
*																			*
****************************************************************************/

void Date::month(string m)
{
	if (m == "Jan")
		m_month = JAN;
	else if (m == "Feb")
		m_month = FEB;
	else if (m == "Mar")	// This checks to see if each month is valid and if so sets that month to the set ENUM type of that month						
		m_month = MAR;		// Uses the Enum later in the program to set as a value for caculations 
	else if (m == "Apr")
		m_month = APR;
	else if (m == "May")
		m_month = MAY;
	else if (m == "Jun")
		m_month = JUN;
	else if (m == "Jul")
		m_month = JUL;
	else if (m == "Aug")
		m_month = AUG;
	else if (m == "Sep")
		m_month = SEP;
	else if (m == "Oct")
		m_month = OCT;
	else if (m == "Nov")
		m_month = NOV;
	else if (m == "Dec")
		m_month = DEC;
	else
	{
		cout << "Month is not valid. Using \"Jan\"" << endl;
		m_month = JAN;
	}

	return;
}

/****************************************************************************
*																			*
*	Function:	day															*
*																			*
*	Purpose:	To set the day of the date to a specified day				*
*																			*
****************************************************************************/

void Date::day(int d)
{
	assert (d >= 1 && d <= 31);		// Sets the day to inputed day by the user
	m_day = d;
	return;
}

/****************************************************************************
*																			*
*	Function:	year														*
*																			*
*	Purpose:	To set the year of the date to a specified year				*
*																			*
****************************************************************************/

void Date::year(int y)
{
	assert (y >= 1601);		// This sets the year to a specified year inputed by the user
	m_year = y;
	return;
}

/****************************************************************************
*																			*
*	Function:	add															*
*																			*
*	Purpose:	To add a specified number of days to the date				*
*																			*
*	Note:		If the integer is positive, the new date will be in the		*
*				future.  If it is negative, the new date will be in the		*
*				past.														*
*																			*
****************************************************************************/

Date Date::add(int n) const
{
	return Date(int(*this) + n);		// Adds days to the date 
}

/****************************************************************************
*																			*
*	Function:	isEqual														*
*																			*
*	Purpose:	To determine whether the invoking date is equal to the		*
*				specified date												*
*																			*
****************************************************************************/

bool Date::isEqual(const Date& d) const
{
	
	return  m_year == d.m_year && m_month == d.m_month && m_day == d.m_day; // Takes the year month and day and determines if they are equal to the specified date
}


/****************************************************************************
*																			*
*	Function:	isBefore													*
*																			*
*	Purpose:	To determine whether the invoking date is less than the		*
*				specified date												*
*																			*
****************************************************************************/

bool Date::isBefore(const Date& d) const
{
	if (m_year < d.m_year)		// This runs through to test if the year is less than the specified year
		return true;

	if (m_year > d.m_year)	// if not returns false 
		return false;

	if (m_month < d.m_month)	// This runs through to test if the month is less than the specified year
		return true;

	if (m_month > d.m_month) // if not it returns false
		return false;

	if (m_day < d.m_day)	// This runs through to test if the day is less than the specified day
		return true;

	if (m_day > d.m_day)	// returns false if not 
		return false;

}
/****************************************************************************
*																			*
*	Function:	input														*
*																			*
*	Purpose:	To get a Date from the input stream.  This month will		*
*				read a month, a day, and a year.							*
*																			*
*	Note:		The date must be entered in the format: Month day, year 	*
*																			*
****************************************************************************/

void Date::input(istream& in)
{
	// Read the month name

	string month_name;
	in >> month_name;

	//	Use the mutator to set the month

	month(month_name);

	//	Get the day and year

	int d;
	in >> d;			// Get day
	day(d);			// Validate and set day

	char c;
	in >> c;			// Get the comma
	assert(c == ',');	// Verify that char is comma

	int y;
	in >> y;			// Get m_year
	year(y);			// Validate and set year

	if (!isValid())
	{
		cout << "The date entered is not a valid date. Date is replaced with the current date" << endl;
		*this = current();
	}

	return;
}

/****************************************************************************
*																			*
*	Function:	output														*
*																			*
*	Purpose:	To write a Date to the output stream.						*
*																			*
*	Note:		The date will be written in the format: Month day, year		*
*																			*
****************************************************************************/

void Date::output(ostream& out) const
{
	out << month() << " " << day() << "," << year();		// Outputs the month day, year

}

/****************************************************************************
*																			*
*	Function:	weekday														*
*																			*
*	Purpose:	To determine the day of the week of the date				*
*																			*
*	Note:		This function uses Zellner's algorithm						*
*																			*
****************************************************************************/

string Date::weekday() const
{
	///	Carry out Zellner's inscrutable algorithm

	int adjMonth = (m_month < 2) ? m_month + 11 : m_month - 1;
	int adjYear = (m_month < 2) ? m_year - 1 : m_year;
	int monthCorr = (26 * adjMonth - 2) / 10;
	int century = adjYear / 100;
	int lastTwo = adjYear % 100;
	int yearCorr = lastTwo + (lastTwo / 4) + (century / 4) + 5 * century;
	int weekday = (m_day + monthCorr + yearCorr) % 7;

	//	Return the name of the day of the week

	switch (weekday)
	{
	case 0: return "Sunday"; break;
	case 1: return "Monday"; break;
	case 2: return "Tuesday"; break;
	case 3: return "Wednesday"; break;
	case 4: return "Thursday"; break;
	case 5: return "Friday"; break;
	case 6: return "Saturday"; break;
	}
}
/****************************************************************************
*																			*
*	Function:	current														*
*																			*
*	Purpose:	To return the current day (real time)						*
*																			*
****************************************************************************/

Date Date::current()
{
//	Get time object and extract its parts

	time_t t = time(0);
	struct tm* curr = localtime(&t);
	return Date(Month(curr->tm_mon), curr->tm_mday, curr->tm_year + 1900);
}


/****************************************************************************
*																			*
*	Function:	isValid														*
*																			*
*	Purpose:	To check whether the date is valid							*
*																			*
****************************************************************************/

bool Date::isValid() const
{
	
	if (m_year >= 1601)		// Test the year inputed to se if it is past the year 1601 or equals too
		return true;
	
	switch (m_month)
	{
	case JAN: return true;		// Runs through to test the case of the month to determine if it is a correct case of one of the 12 months 
	case FEB: return true;
	case MAR: return true;
	case APR: return true;
	case MAY: return true;
	case JUN: return true;
	case JUL: return true;
	case AUG: return true;
	case SEP: return true;
	case OCT: return true; 
	case NOV: return true; 
	case DEC: return true;
	}

	if (m_day >= 1 && m_day <= 31)		// Determines if the day is 1 to 31
		return true;
}
/****************************************************************************
*																			*
*	Function:	operator int()												*
*																			*
*	Purpose:	To convert the date to an integer representing the umber	*
*				of days since Jan 1, 1601									*
*																			*
****************************************************************************/

Date::operator int() const
{
	//	Count the days in the years since 1601

	int years = m_year - 1601;					// Years since 1601
	int num_of_days = 365 * years;				// 365 days in a year
	num_of_days += (years / 4);					// Add 1 for each leap year
	num_of_days -= (years / 100);				// Sub 1 for century year
	num_of_days += (years / 400);				// Add 1 for cent leap year

	//	Add the days in the past months of this year

	for (Month m = JAN; m < m_month; m = (Month)(m + 1))
		num_of_days += daysInMonth(m, m_year);	// Add days in months

	//	Add the number of days into the current month

	num_of_days += m_day - 1;					// Counts days into month

	//	Return the number of days since Jan 1, 1601

	return num_of_days;
}

/****************************************************************************
*																			*
*	Function:	isLeapYear													*
*																			*
*	Purpose:	To determine whether the specified year is a leap year		*
*																			*
*	Note:		A year must be a multiple of 4 to be a leap year. The		*
*				exceptions are the century years that are not multiples of	*
*				400.														*
*																			*
****************************************************************************/

bool Date::isLeapYear(int y)
{
	if (y % 4 != 0)
		return false;		//Determines if the year inputed into the program is a leap year testing it to see if it is a multiple of 4, 400, or 100

	if (y % 400 == 0)
		return true;

	if (y % 100 == 0)
		return false;

	return true;
}

/****************************************************************************
*																			*
*	Function:	daysInMonth													*
*																			*
*	Purpose:	To return the number of days in the specified month			*
*																			*
*	Note:		The year is also a parameter since the number of days in	*
*				February depends on the year.  The default value for the	*
*				year is 1601, which was not a leap year.					*
*																			*
****************************************************************************/

int Date::daysInMonth(Month m, int y)
{
	switch(m)
	{
	case JAN: return 31;
	case FEB: return isLeapYear(y) ? 29 : 28;	// uses the leap year function to determine how many days were in the month of FEB
	case MAR: return 31;
	case APR: return 30;		//This allows the user to see how many days are in a ceratin month of the year
	case MAY: return 31;
	case JUN: return 30;
	case JUL: return 31;
	case AUG: return 31;
	case SEP: return 30;
	case OCT: return 31;
	case NOV: return 30;
	case DEC: return 31;
	default:
		Date();
		return 0;
	}
}

/****************************************************************************
*																			*
*	Function:	operator>>													*
*																			*
*	Purpose:	To read a date from the specified input stream				*
*																			*
****************************************************************************/

istream& operator>>(istream& in, Date& date)
{
	date.input(in);
	return in;
}

/****************************************************************************
*																			*
*	Function:	operator<<													*
*																			*
*	Purpose:	To write a date to the specified output stream				*
*																			*
****************************************************************************/

ostream& operator<<(ostream& out, const Date& date)
{
	date.output(out);
	return out;
}

/****************************************************************************
*																			*
*	Function:	operator+(Date, int)										*
*																			*
*	Purpose:	To find the date that is a specified number of days after	*
*				the given date												*
*																			*
*	Note:		The date will be in the past if the integer is negative		*
*																			*
****************************************************************************/

Date operator+(const Date& date, const int n)
{
	return date.add(n);
}

/****************************************************************************
*																			*
*	Function:	operator-(Date, int)										*
*																			*
*	Purpose:	To find the date that is a specified number of days before	*
*				the given date												*
*																			*
*	Note:		The date will be in the future if the integer is negative	*
*																			*
****************************************************************************/

Date operator-(const Date& date, const int n)
{
	return date.add(-n);
}

/****************************************************************************
*																			*
*	Function:	operator++(Date)											*
*																			*
*	Purpose:	To pre-increment the specified date							*
*																			*
****************************************************************************/

Date & Date::operator++()
{
	*this = *this + 1;
	return *this;
}

/****************************************************************************
*																			*
*	Function:	operator++(Date, int)										*
*																			*
*	Purpose:	To post-increment the specified date						*
*																			*
*	Note:		The "dummy" parameter of int is C++'s way of indicating		*
*				that this is the POST-increment operator. In usage, no		*
*				integer is provided.										*
*																			*
****************************************************************************/

Date Date::operator++(int)
{
	Date org = *this;
	*this = *this + 1;
	return org;
}

/****************************************************************************
*																			*
*	Function:	operator--(Date)											*
*																			*
*	Purpose:	To pre-decrement the specified date							*	
*																			*
****************************************************************************/

Date & Date::operator--()
{
	*this = *this - 1;
	return *this;
}

/****************************************************************************
*																			*
*	Function:	operator--(Date, int)										*
*																			*
*	Purpose:	To post-decrement the specified date						*
*																			*
*	Note:		The "dummy" parameter of int is C++'s way of indicating		*
*				that this is the POST-decrement operator. In usage, no		*
*				integer is provided.										*
*																			*
****************************************************************************/

Date Date::operator--(int)
{
	Date original = *this;		
	*this = *this - 1;
	return original;
}

/****************************************************************************
*																			*
*	Function:	operator==													*
*																			*
*	Purpose:	To determine whether the first date is equal to the second	*
*				date														*
*																			*
****************************************************************************/

bool operator==(const Date& date1, const Date& date2)
{
	return date1.isEqual(date2);
}

/****************************************************************************
*																			*
*	Function:	operator!=													*
*																			*
*	Purpose:	To determine whether the first date is not equal to the		*
*				second date													*
*																			*
****************************************************************************/

bool operator!=(const Date& date1, const Date& date2)
{
	return !(date1.isEqual(date2));
}

/****************************************************************************
*																			*
*	Function:	operator<													*
*																			*
*	Purpose:	To determine whether the first date is earlier than the		*
*				second date													*
*																			*
****************************************************************************/

bool operator<(const Date& date1, const Date& date2)
{
	return date1.isBefore(date2);
}

/****************************************************************************
*																			*
*	Function:	operator>													*
*																			*
*	Purpose:	To determine whether the first date is later than the		*
*				second date													*
*																			*
****************************************************************************/

bool operator>(const Date& date1, const Date& date2)
{
	return date2.isBefore(date1);
}

/****************************************************************************
*																			*
*	Function:	operator<=													*
*																			*
*	Purpose:	To determine whether the first date is earlier than or		*
*				equal to the second date									*
*																			*
****************************************************************************/

bool operator<=(const Date& date1, const Date& date2)
{
	return !(date1 > date2);
}

/****************************************************************************
*																			*
*	Function:	operator>=													*
*																			*
*	Purpose:	To determine whether the first date is later than or equal	*
*				to the second date											*
*																			*
****************************************************************************/

bool operator>=(const Date& date1, const Date& date2)
{
	return !(date1 < date2);

}

/****************************************************************************
*																			*
*	Function:	operator-(Date, Date)										*
*																			*
*	Purpose:	To return the number of days between the two dates			*
*																			*
****************************************************************************/

int operator-(const Date& date1, const Date& date2)
{
	return int(date1) - int(date2);
}
