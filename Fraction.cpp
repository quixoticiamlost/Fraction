#ifndef FRACTION_CPP
#define FRACTION_CPP

#include "Fraction.h"
#include "pmath.h"
#include <cmath>

Fraction::Fraction():m_numerator(0), m_denominator(1){}

Fraction::Fraction(int numerator, int denominator)
{
	using pmath;
	// input is positive : erase possible negative signs
	if ((!is_neg(numerator))&&(!is_neg(denominator)) || (is_neg(numerator)) && (is_neg(denominator))
	{	
		this->m_numerator = abs(numerator);
		this->m_denominator = abs(denominator);
	}
	// else it is negative: erase possible negatives and store negative sign in numerator 
	else 
	{
		this->m_numerator = -abs(numerator);
		this->m_denominator = abs(denominator);
	}
	reduce();
}

void Fraction::reduce()
{
	int factor = pmath::gcf(this->m_numerator, this->m_denominator);
	this->m_numerator / factor;
	this->m_denominator /= factor;
}
#endif
