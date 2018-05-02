//Header for implement fraction and mixed fraction number
//@Zheng.Sun15	ID:1507820
#ifndef _FRACTION
#define _FRACTION

int commonDivisor(int a, int b);
int intParser();
//iFraction convertF(const Fraction& x);
class iFraction;
class Fraction {
	friend iFraction convertF(Fraction& x);
private:
	int top;	//Numerator
	int bottom; //Denominator
public:
	Fraction();
	Fraction(int a, int b);
	Fraction(int a);
	int getTop()const; //get top of fraction
	int getBottom()const;//get bottom of fraction
	bool isZero()const;//determine trivial solution
	void reduceToProperFraction();//reduece to proper fraction
	void show_Fraction();//formatted 'show' display
	void show_Decimal();//formated display in decimal
	void print_Fraction();//formated display
	void set_numerator(int x);//reset top
	void set_denominator(int x);//reset bottom
	void cmp_Fraction(const Fraction& x) const;//cmp
	Fraction add_Fraction(const Fraction& x) const;//'+'op
	Fraction sub_Fraction(const Fraction& x) const;//'-'op
	Fraction mul_Fraction(const Fraction &x) const;//'*'op
	Fraction div_Fraction(const Fraction &x) const;//'/'op
	double to_Decimal(); // convert to decimal
};

#endif