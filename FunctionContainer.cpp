#pragma once
#include <iostream>

using namespace std;

class FunctionContainer
{
protected:
	double a;
	double x;
	double b;
	double c;

public:
	virtual double invoke() = 0;
};