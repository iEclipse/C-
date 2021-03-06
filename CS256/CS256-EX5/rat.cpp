#include "rat.h"

// These functions can be useful for calculations with fractions
int gcd(int x, int y)
{
	if (y == 0) 
		return x;
	return gcd(y, x % y);
}

int lcm(int x, int y)
{
	return (x * y) / gcd(x, y);
}

rat::rat() : num(0), den(1){};

rat::rat(int n) : num(n), den(1){};

rat::rat(int n, int d) : num(n), den(d){
	if (d == 0){
		num = 0;
		den = 1;
	}
}