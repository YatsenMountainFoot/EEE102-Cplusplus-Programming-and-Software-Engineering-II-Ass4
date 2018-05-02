#ifndef _IFRACTION
#define _IFRACTION
#include "Fraction.h"

class iFraction : public Fraction {

private:
	int integerPart = 0;	//integer part of iFraction
public:
	iFraction(int top = 0, int bottom = 1, int integerPart = 0); //constructor utilizing elements
	iFraction(const Fraction& x);	// constructor using Fraction
	void print_iFraction()const;	// used to display contents
};

#endif