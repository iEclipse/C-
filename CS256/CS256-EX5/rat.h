#ifndef RAT_H
#define RAT_H

#include <iostream>
#include <string>
#include <sstream>

class RatTester;

class rat
{
    friend class RatTester;

private:
    int num,den;
public:
	rat();
	rat(int num);
	rat(int num, int den);
	~rat();
};

#endif