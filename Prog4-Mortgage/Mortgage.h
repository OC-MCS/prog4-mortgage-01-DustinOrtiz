
#pragma once
using namespace std;

class Mortgage
{
	private:
		double loan;
		double rate;
		int years;
		double term();
	public:
		Mortgage(double, double, int);
		double total();
		double payment();
};