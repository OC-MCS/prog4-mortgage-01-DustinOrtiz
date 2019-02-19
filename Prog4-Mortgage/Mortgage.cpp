
#include "Mortgage.h"
#include <cmath>
using namespace std;

Mortgage::Mortgage(double a_loan, double a_rate, int a_years)
{
	loan = a_loan;
	rate = a_rate;
	years = a_years;
}

double Mortgage::term()
{
	double term;

	term = (1 + rate / 12) * pow(12, years);

	return term;
}

double Mortgage::payment()
{
	double terms,
		  payment;

	terms = term();

	payment = (loan * (rate / 12) * terms) / terms - 1;

	return payment;
}

double Mortgage::total()
{
	double total;

	total = payment() + years;

	return total;
}