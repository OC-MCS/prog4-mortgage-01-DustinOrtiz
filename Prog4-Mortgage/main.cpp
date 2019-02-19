
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
	bool valid = false;
	string input;
	double loan,
		   rate;
	int years;

	cout << "---Mortgage Payment----" << endl;

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

	cout << showpoint << setprecision(2);

	Mortgage mort(loan, rate, years);

	cout << "\nMonthly Payment: " << mort.payment() << endl;
	cout << "\nTotal amount paid to the bank: " << mort.total() << endl;

	return 0;
}

bool badLoan(string input, double &loan)
{
	bool validLoan = true;
	double num; 

	try
	{
		num = stod(input);
		loan = num;
	}

	catch (const std::exception&)
	{
		validLoan = false;
	}

	return validLoan; 
}

bool badRate(string input, double &rate)
{
	bool validRate = true; 
	double num; 

	try
	{
		num = stod(input);
		rate = num;
	}

	catch (const std::exception&)
	{
		validRate = false;
	}

	return validRate;
}

bool badYears(string input, int &years)
{
	bool validYears = true;
	int num;

	try
	{
		num = stoi(input);
		years = num;
	}

	catch (const std::exception&)
	{
		validYears = false;
	}

	return validYears;
}