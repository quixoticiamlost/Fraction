#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	void reduce();
public:
	Fraction();
	Fraction(int numerator, int denominator);
	//Fraction(double number);
	
};




#endif
