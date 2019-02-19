
//=============================
// Dustin Ortiz
// 20 February 2019
// Programming Assignment #4
// Desciption: Mortgage Payment
//=============================

#include <iostream>
#include <string>
#include <iomanip>
#include "Mortgage.h"
using namespace std;

bool badLoan(string, double &);

bool badRate(string, double &);

bool badYears(string, int &);

int main()
{
	bool valid = false; // Incorrect data entry.
	string input; // Users input in string.
	double loan, // Users input in double.
		   rate; // Users input in double.
	int years; // Users input in int.

	cout << "\n---Mortgage Payment----" << endl;

	do
	{
		cout << "\nEnter the dollar amount of the loan: $";
		getline(cin, input);

		if (!badLoan(input, loan) || loan < 0)
		{
			cout << "\nInvalid Entry! Try Again!" << endl;
		}
		else
		{
			valid = true;
		}

	} while (!valid);

	valid = false;

	do
	{
		cout << "\nEnter the annual interest rate: ";
		getline(cin, input);

		if (!badRate(input, rate) || rate < 0)
		{
			cout << "\nInvalid Entry! Try Again!" << endl;
		}
		else
		{
			valid = true;
		}

	} while (!valid);

	valid = false;

	do
	{
		cout << "\nEnter the number of years of the loan: ";
		getline(cin, input);

		if (!badYears(input, years) || years < 0)
		{
			cout << "\nInvalid Entry! Try Again!" << endl;
		}
		else
		{
			valid = true;
		}

	} while (!valid);

	Mortgage m1(loan, rate, years); // Mortgage payment.

	cout << fixed << setprecision(2);
	cout << "\nMonthly Payment: $" << m1.payment() << endl;
	cout << "\nTotal amount paid to the bank: $" << m1.total() << endl;

	return 0;
}

//==============================================
// badLoan: Determines if users input was valid.
// Parameters:
// input: Users input in string.
// loan: Users input in int.
// Return Type: bool (validLoan).
//==============================================

bool badLoan(string input, double &loan)
{
	bool validLoan = true; // Valid input.
	double num; // Users input changed.

	try
	{
		num = stod(input);
		loan = num;
	}

	catch (const std::exception&)
	{
		validLoan = false;
	}

	return validLoan; // Returns valid loan.
}

//==============================================
// badRate: Determines if users input was valid.
// Parameters:
// input: Users input in string.
// rate: Users input in int.
// Return Type: bool (validRate).
//==============================================

bool badRate(string input, double &rate)
{
	bool validRate = true; // Valid input.
	double num; // Users input changed.

	try
	{
		num = stod(input);
		rate = num;
	}

	catch (const std::exception&)
	{
		validRate = false;
	}

	return validRate; // Returns valid rate.
}

//===============================================
// badYears: Determines if users input was valid.
// Parameters:
// input: Users input in string.
// years: Users input in int.
// Return Type: bool (validYears).
//===============================================

bool badYears(string input, int &years)
{
	bool validYears = true; // Valid input.
	int num; // Users input changed.

	try
	{
		num = stoi(input);
		years = num;
	}

	catch (const std::exception&)
	{
		validYears = false;
	}

	return validYears; // Returns valid years.
}