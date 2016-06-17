#ifndef PMATH_CPP
#define PMATH_CPP

#include "pmath.h"

bool pmath::is_neg(int number)
{
	return number > 0 ? false : true;
}

int pmath::gcd(int a, int b)
{
	int c;
 
    	while (b != 0)
    	{
        	c = b;
        	b = a % b;
        	a = c; 
    	}
    	return a;
}

#endif