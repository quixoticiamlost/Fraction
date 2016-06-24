#ifndef FRACTION_CPP
#define FRACTION_CPP

#include "Fraction.h"
#include "pmath.h"
#include <cassert>
#include <cmath>
#include <string>

Fraction::Fraction():m_numerator(0), m_denominator(1){}

Fraction::Fraction(int number) : m_numerator(number), m_denominator(1){}

Fraction::Fraction(int numerator, int denominator)
{	
	assert(denominator != 0);
	// input is positive : erase possible negative signs
	if ((pmath::is_neg<int>(numerator) && pmath::is_neg<int>(denominator)) ||
		(!pmath::is_neg<int>(numerator) && !pmath::is_neg<int>(denominator)))
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

Fraction::Fraction(double number) 
{	
	// set precision 
	const int prec = 10000;
	
	// split input to integral and fractional parts 
	double whole_part = 0;
	double frac_part = modf(number, &whole_part);
	
	// cast fractional part as integer 
	int whole_part_toint = (int)whole_part;
	int frac_part_toint = (int)round(frac_part *= prec); 

	this->m_numerator = whole_part_toint * prec + frac_part_toint;
	this->m_denominator = prec; 
	
	reduce();
	

}

void Fraction::reduce()
{
	int factor = abs(pmath::gcd(this->m_numerator, this->m_denominator));
	this->m_numerator /= factor;
	this->m_denominator /= factor;
}

Fraction & Fraction::operator= (const Fraction & rhs)
{	// check for self-assignment 
	if (this == &rhs)
	{
		return *this;
	}
	this->m_numerator = rhs.m_numerator;
	this->m_denominator = rhs.m_denominator;
	return *this;
}

Fraction & Fraction::operator+= (const Fraction & rhs) 
{
	this->m_numerator = this->m_numerator * rhs.m_denominator + this->m_denominator * rhs.m_numerator;
	this->m_denominator *= rhs.m_denominator;
	return *this;
}

Fraction & Fraction::operator-= (const Fraction & rhs) 
{
	this->m_numerator = this->m_numerator * rhs.m_denominator - this->m_denominator * rhs.m_numerator;
	this->m_denominator *= rhs.m_denominator;
	return *this;
}

Fraction & Fraction::operator*= (const Fraction & rhs) 
{
	this->m_numerator *= rhs.m_numerator;
	this->m_denominator *= rhs.m_denominator;
	return *this;
}

Fraction & Fraction::operator/= (const Fraction & rhs) 
{	
	this->m_numerator *= rhs.m_denominator;
	this->m_denominator /= rhs.m_numerator;
	return *this;
}

const Fraction Fraction::operator + (const Fraction & rhs) 
{
	return Fraction(*this) += rhs;
}

const Fraction Fraction::operator - (const Fraction & rhs) 
{
	return Fraction(*this) -= rhs;
}

const Fraction Fraction::operator * (const Fraction & rhs) 
{
	return Fraction(*this) *= rhs;
}

const Fraction Fraction::operator / (const Fraction & rhs) 
{
	return Fraction(*this) /= rhs;
}

bool Fraction::operator==(const Fraction & rhs) const
{
	return (this->m_numerator == rhs.m_numerator) && (this->m_denominator == rhs.m_denominator);

}
bool Fraction::operator!=(const Fraction & rhs) const
{
	return !(*this == rhs);
}



#endif
