#ifndef PMATH_H
#define PMATH_H

namespace pmath
{
	bool is_neg(int number);
	
	int gcd(int a, int b);

	template<typename T>
	bool is_neg(T number)
	{
		return number > 0 ? false : true;
	}
}

#endif