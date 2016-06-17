#ifndef FRACTION_CPP
#define FRACTION_CPP

#include "Fraction.h"
#include "pmath.h"
#include <cmath>

Fraction::Fraction():m_numerator(0), m_denominator(1){}

Fraction::Fraction(int numerator, int denominator)
{
	using pmath;
	// input is positive
	if ((!is_neg(numerator))&&(!is_neg(denominator)) || (is_neg(numerator)) && (is_neg(denominator))
	{	
		this->m_numerator = reduceabs(numerator)
	}
	// else it is negative 
	else 
	{
	}
}

void Fraction::reduce(int numerator, int denominator)
{
		
}
#endif