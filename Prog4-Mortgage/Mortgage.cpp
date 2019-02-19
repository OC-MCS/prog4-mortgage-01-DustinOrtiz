
#include "Mortgage.h"
#include <cmath>
using namespace std;

//===========================
// Mortgage: Sets the values.
// Parameters:
// aLoan: loan data. 
// aRate: Rate data.
// someYears: Years data
// Return Type: None.
//===========================

Mortgage::Mortgage(double aLoan, double aRate, int someYears)
{
	loan = aLoan; // Loan data.
	rate = aRate; // Rate data.
	years = someYears; // Years data.
}

//============================
// term: Term mathematics.
// Parameters:
// none.
// Return Type: double (term).
//============================

double Mortgage::term()
{
	double term; // Terms mathematics.

	term = (1 + rate / 12) * pow(12, years);

	return term; // Returns term to payment.
}

//===============================
// payment: Payment mathematics.
// Parameters:
// none.
// Return Type: double (payment).
//===============================

double Mortgage::payment()
{
	double terms, // Terms mathematics.
		  payment; // Monthly payment.

	terms = term();

	payment = loan * rate / 12 * terms / terms - 1;

	return payment; // Returns monthly payment.
}

//=============================
// total: Total mathematics.
// Parameters:
// none.
// Return Type: double (total).
//=============================

double Mortgage::total()
{
	double total; // Total bank payment.

	total = payment() * (years * 12);

	return total; // Returns bank total.
}