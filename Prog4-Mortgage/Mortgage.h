
#pragma once
using namespace std;

class Mortgage // Mortgage information
{
	private:
		double loan; // Loan data.
		double rate; // Rate data.
		int years; // Years data.
		double term();
	public:
		Mortgage(double, double, int);
		double total();
		double payment();
};