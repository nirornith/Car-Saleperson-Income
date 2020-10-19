/******************************************************************
 * Program Filename: income.cpp
 * Author: Zoe Rae Downen
 * Date: October 7th, 2020
 * Description: This program calculates and prints the gross income
 * 	of a car salesperson, how much in taxes they have to pay,
 * 	and how much of their income is left after taxes
 * Input: monthly salary, number of months worked in a year, cost
 * 	of a car, number of cars sold, number of misconducts
 * 	observed, in which tax year, in which state
 * Output: gross income, total taces, remaining income after taxes
 * ****************************************************************/

#include <iostream> 
#include <stdlib.h>
#include <math.h>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	//variable declarations for input
	double monthlySalary, carCost;
	int numOfMonths, numSold, misconducts, taxYear;
	char state;
	
	//request all input and test cases
	cout << "Enter your monthly salary: ";
	cin >> monthlySalary;

	cout << "Enter the number of months you worked in the past year: ";
	cin >> numOfMonths;
	while(numOfMonths < 0 || numOfMonths > 12) {
		cout << "Invalid number of months. Try again: ";
		cin >> numOfMonths;
	}

	cout << "Enter the cost of the car: ";
	cin >> carCost;

	cout << "Enter the number of cars you've sold in the past year: ";
	cin >> numSold;
	while(numSold < 0) {
		cout << "Invalid number of cars sold. Try again: ";
		cin >> numSold;
	}

	cout << "Enter the number of misconducts observed in the past year: ";
	cin >> misconducts;
	while(misconducts < 0) {
		cout << "Invalid number of misconducts. Try again: ";
		cin >> misconducts;
	}

	cout << "Which tax year are you in, enter 2018 or 2019: ";
	cin >> taxYear;
	while(taxYear != 2019 && taxYear != 2018) {
		cout << "Invalid year. Try again: ";
		cin >> taxYear;
	}

	cout << "Which state are you in, enter A, B, or C: ";
	cin >> state;
	while(state != 'A' && state != 'B' && state != 'C') {
		cout << "Invalid State. Try again: ";
		cin >> state;
	}

	//calculate gross income
	double annualSalary = monthlySalary * (double) numOfMonths;
	double profit = (double) numSold *(carCost * ((double)(5 + rand() % (6))/100.0));
	int deduction;
	if(misconducts == 0) { 
		deduction = 0;
	} else {
		deduction = 100 * pow(2, misconducts);
	}
	double grossIncome = annualSalary + (profit * 0.02) - (double) deduction;
	
	//calculate total taxes based on tax year and state residence
	double taxes;
	if(taxYear == 2018) {
		//calculates income-based tax depending on user's residency
		switch(state) {
			case 'A':
				taxes = grossIncome * 0.06;
				break;
			case 'B':
				if(grossIncome < 2000) {
					taxes = 0.0;
				} else if(grossIncome > 2000 && grossIncome < 10000) {
					taxes = 100.0;
				} else {
					taxes = ((grossIncome - 10000) * 0.1) + 100;
				}
				break;
			case 'C':
				if(grossIncome < 3500) {
					taxes = grossIncome * 0.05;
				} else if(grossIncome > 3500 && grossIncome < 9000) {
					taxes = ((grossIncome - 3500) * 0.07) + 175;
				} else if(grossIncome > 9000 && grossIncome < 12500) {
					taxes = ((grossIncome - 9000) * 0.09) + 560;
				} else {
					taxes = ((grossIncome - 125000) * 0.099) + 11000;
				}
				break;
		}
	//calculates taxes within 2019 year instead of 2018 year
	} else {
		switch(state) {
			case 'A':
				taxes = grossIncome * 0.08;
				break;
			case 'B': 
				if(grossIncome < 2500) {
					taxes = 0.0;
				} else if(grossIncome > 2500 && grossIncome < 10000) {
					taxes = 115.0;
				} else {
					taxes = ((grossIncome - 10000) * 0.105) + 115;
				}
				break;
			case 'C':
				if(grossIncome < 3450) {
					taxes = grossIncome * 0.05;
				} else if(grossIncome > 3450 && grossIncome < 8700) {
					taxes = ((grossIncome - 3450) * 0.07) + 172.5;
				} else if(grossIncome > 8700 && grossIncome < 125000) {
					taxes = ((grossIncome - 8700) * 0.09) + 540;
				} else {
					taxes = ((grossIncome - 125000) * 0.099) + 11007;
				}
				break;
		}
	}
	
	//Calculate remaining income and print all output
	double incomeLeft = grossIncome - taxes;
	cout << "Gross Income: " << grossIncome << endl;
	cout << "Taxes: " << taxes << endl;
	cout << "Income Left: " << incomeLeft << endl;

	return 0;	

}

