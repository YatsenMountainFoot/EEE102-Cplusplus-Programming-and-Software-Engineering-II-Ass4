//Main file for demonstrate iFraction
//@Zheng.Sun15	ID:1507820
#include <iostream>
#include "Fraction.h"
#include "iFraction.h"
const int MAX = 1;

int main() {

	using std::cout;
	using std::cin;
	using std::endl;
	int i = 0;		//loop counter for initialize Fraction array
	int intPart;	//temporary storage for integer part of mixed Fraction
	int numerator;	//temporary storage for top and bottom of Fraction
	int denominator;

	Fraction F[MAX];//array to store Fraction objects

	//regular demonstration
	cout << "This program demostrates some simple behaviors of iFraction class" << endl;
	cout << "Regular test: iFraction(2, 3, 1) is "; iFraction(2, 3, 1).print_iFraction(); cout << endl;

	cout << "Please Enter elements of fraction for demostration of convertF." << endl;
	//read and parse int type data into objets
	cout << "\tEnter the integer part:";
	intPart = intParser();
	cout << "\tEnter the numerator:";
	numerator = intParser();
	cout << "\tEnter the denominator (wnormalized if abs smaller than numerator) :";
	while ((denominator = intParser()) == 0)//exlude denominator = 0
	cout << "\t\tDenominator cannot be 0. Try again: ";
	iFraction x = iFraction(numerator, denominator, intPart);//construct Fraction into array
	cout << "The mixed Fraction entered is: "; x.print_iFraction(); cout << endl << endl;


	cout << "Please Enter " << MAX <<" fraction for demostration of convertF." << endl;
	for (i = 0; i < MAX; i++) {//read and parse int type data into objets
		cout << "fraction #" << i + 1 << ":";
		cout << "\tEnter the numerator:";
		numerator = intParser();
		cout << "\t\tEnter the denominator:";
		while ((denominator = intParser()) == 0)//exlude denominator = 0
			cout << "\t\tDenominator cannot be 0. Try again: ";
		F[i] = Fraction(numerator, denominator);//construct Fraction into array
	}
	cout << "The original Fraction is "; F[0].print_Fraction(); cout << endl; //dynamic demonstration of 
	cout << "By apply convertF() we got mixed Fraction: "; convertF(F[0]).print_iFraction(); cout << endl;

	return 0;
}




//Euclidean algorithm to solve the biggest common divissor
int commonDivisor(int a, int b) {

	int r;
	for (; b != 0;) {
		r = a%b;
		a = b;
		b = r;
	}

	return a;
}

//to Parse an int type value from the input 
int intParser() {
	using std::cin;
	using std::cout;
	int temp;
	bool isErr = true;
	//while (input failed) or (input succeeded with redundant tail, clear steream and repeat)
	while ((isErr = !(cin >> temp)) || (!isErr && cin.get() != '\n')) {
		if (isErr) { cin.clear(); }
		//reset cin
		while (cin.get() != '\n')//clear a whole line
			continue;
		cout << "\t\tPlease enter an integer: ";
	}
	return temp;
}

