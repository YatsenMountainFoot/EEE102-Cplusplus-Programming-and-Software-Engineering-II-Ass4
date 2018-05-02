
//Source file for menber function of class iFraction
//@Zheng.Sun15	ID:1507820
#include<iostream>
#include "iFraction.h"
//constructor method accepts the intger part, top of Fraction part, bottom of Fraction part
iFraction::iFraction(int top, int bottom, int intP) : Fraction(top + intP*bottom, bottom) {
	integerPart = (int)this->to_Decimal();
	this->reduceToProperFraction();
}
//constructor method accepts a Fraction to construct iFraction
iFraction::iFraction(const Fraction& x) : Fraction(x) { //copy constructor
	integerPart = (int)this->to_Decimal();
	this->reduceToProperFraction();
}
//display the contents of iFraction
void iFraction::print_iFraction()const {
	if (this->integerPart > 0 && !isZero())
		std::cout << this->integerPart << " + " << getTop() << "/" << getBottom();
	else if (this->integerPart > 0 && isZero())
		std::cout << this->integerPart;
	else if (this->integerPart == 0 && !isZero())
		std::cout << getTop() << "/" << getBottom();
	else if (this->integerPart == 0 && isZero())
		std::cout << "0";
	else if (this->integerPart < 0 && !isZero())
		std::cout << "-(" << (-1)*this->integerPart << " + " << (-1)*getTop() << "/" << getBottom() << ")";
	else if (this->integerPart < 0 && isZero())
		std::cout << this->integerPart;
}