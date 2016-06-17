#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	static void reduce(int numerator, int denominator);
public:
	Fraction();
	Fraction(int numerator, int denominator);
	//Fraction(double number);
	
};




#endif