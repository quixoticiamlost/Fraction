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
	Fraction(int number);
	Fraction(int numerator, int denominator);
	Fraction(double number);
	
	Fraction & operator= (const Fraction & rhs);

	Fraction & operator+= (const Fraction & rhs);
	Fraction & operator-= (const Fraction & rhs);
	Fraction & operator*= (const Fraction & rhs);
	Fraction & operator/= (const Fraction & rhs);

	const Fraction operator + (const Fraction & rhs);
	const Fraction operator - (const Fraction & rhs);
	const Fraction operator * (const Fraction & rhs);
	const Fraction operator / (const Fraction & rhs);

	bool operator==(const Fraction & rhs) const;
	bool operator!=(const Fraction & rhs) const;
 
	
};




#endif
