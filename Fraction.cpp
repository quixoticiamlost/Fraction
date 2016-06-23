#ifndef FRACTION_CPP
#define FRACTION_CPP

#include "Fraction.h"
#include "pmath.h"
#include <cmath>

Fraction::Fraction():m_numerator(0), m_denominator(1){}

Fraction::Fraction(int number) : m_numerator(number), m_denominator(1) {}

Fraction::Fraction(int numerator, int denominator)
{
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

void Fraction::reduce()
{
	int factor = pmath::gcd(this->m_numerator, this->m_denominator);
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

Fraction::operator double()
{
	return this->m_numerator / this->m_denominator;
}
#endif
